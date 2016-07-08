#include "BatchRenderer2D.h"


namespace Fd {
	namespace Graphics {

		BatchRenderer2D::BatchRenderer2D()
		{
			glGenVertexArrays(1, &m_vao);
			glGenBuffers(1, &m_vbo);

			glBindVertexArray(m_vao);
			glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
			glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(RENDERER_BUFFER_SIZE), nullptr, GL_DYNAMIC_DRAW);
			glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
			glEnableVertexAttribArray(SHADER_COLOR_INDEX);
			glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, static_cast<GLsizei>(RENDERER_VERTEX_SIZE), (const GLvoid*)0);
			glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_FLOAT, GL_FALSE, static_cast<GLsizei>(RENDERER_VERTEX_SIZE), (const GLvoid*)(3 * sizeof(GLfloat)));
			glBindBuffer(GL_ARRAY_BUFFER, 0);

			GLuint *indices = new GLuint[RENDERER_INDICES_SIZE];
			
			int offset = 0;
			for (int i{ 0 }; i < RENDERER_INDICES_SIZE; i += 6) {
				indices[  i  ] = offset + 0;
				indices[i + 1] = offset + 1;
				indices[i + 2] = offset + 2;

				indices[i + 3] = offset + 2;
				indices[i + 4] = offset + 3;
				indices[i + 5] = offset + 0;

				offset += 4;
			}

			m_ibo = new IndexBuffer(indices, RENDERER_INDICES_SIZE);

			glBindVertexArray(0);
		}

		BatchRenderer2D::~BatchRenderer2D()
		{
			delete m_ibo;
			glDeleteBuffers(1, &m_vbo);
		}

		void BatchRenderer2D::begin()
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
			m_buffer = static_cast<VertexData*>(glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY));
		}

		void BatchRenderer2D::submit(const Renderable2D * renderable)
		{
			const Maths::vec3& position = renderable->getPosition();
			const Maths::vec2& size = renderable->getSize();
			const Maths::vec4& color = renderable->getColor();

			m_buffer->vertex = position;
			m_buffer->color = color;
			m_buffer++;

			m_buffer->vertex = Maths::vec3(position.x, position.y + size.y, position.z);
			m_buffer->color = color;
			m_buffer++;

			m_buffer->vertex = Maths::vec3(position.x + size.x, position.y + size.y, position.z);
			m_buffer->color = color;
			m_buffer++;

			m_buffer->vertex = Maths::vec3(position.x + size.x, position.y, position.z);
			m_buffer->color = color;
			m_buffer++;

			m_indexCount += 6;
		}

		void BatchRenderer2D::end()
		{
			glUnmapBuffer(GL_ARRAY_BUFFER);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		void BatchRenderer2D::flush()
		{
			glBindVertexArray(m_vao);
			m_ibo->bind();

			glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, 0);

			m_ibo->unbind();
			glBindVertexArray(0);

			m_indexCount = 0;
		}

	}
}