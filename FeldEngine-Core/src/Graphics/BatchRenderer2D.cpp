/*
* The MIT License(MIT)
*
* Copyright(c) 2016 Victor DENIS (victordenis01@gmail.com)
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files(the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions :
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#include "BatchRenderer2D.h"
#include "Renderable2D.h"

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
			glEnableVertexAttribArray(SHADER_UV_INDEX);
			glEnableVertexAttribArray(SHADER_TID_INDEX);
			glEnableVertexAttribArray(SHADER_COLOR_INDEX);

			glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, static_cast<GLsizei>(RENDERER_VERTEX_SIZE), (const GLvoid*)0);
			glVertexAttribPointer(SHADER_UV_INDEX, 2, GL_FLOAT, GL_FALSE, static_cast<GLsizei>(RENDERER_VERTEX_SIZE), (const GLvoid*)(offsetof(VertexData, VertexData::uv)));
			glVertexAttribPointer(SHADER_TID_INDEX, 1, GL_FLOAT, GL_FALSE, static_cast<GLsizei>(RENDERER_VERTEX_SIZE), (const GLvoid*)(offsetof(VertexData, VertexData::tid)));
			glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_UNSIGNED_BYTE, GL_TRUE, static_cast<GLsizei>(RENDERER_VERTEX_SIZE), (const GLvoid*)(offsetof(VertexData, VertexData::color)));
			
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
			const std::vector<Maths::vec2>& uv = renderable->getUV();
			const GLuint tid = renderable->getTID();

			unsigned c{};

			float ts{ 0.0f };
			if (tid > 0) {
				bool found{ false };

				for (size_t i{ 0 }; i < m_textureSlots.size(); ++i) {
					if (m_textureSlots[i] == tid) {
						ts = static_cast<float>(i + 1);
						found = true;
						break;
					}
				}

				if (!found) {
					if (m_textureSlots.size() >= 32) {
						end();
						flush();
						begin();
					}
					m_textureSlots.push_back(tid);
					ts = static_cast<float>(m_textureSlots.size());
				}
			}
			else {
				int r{ static_cast<int>(color.x * 255.0f) };
				int g{ static_cast<int>(color.y * 255.0f) };
				int b{ static_cast<int>(color.z * 255.0f) };
				int a{ static_cast<int>(color.w * 255.0f) };

				c = a << 24 | b << 16 | g << 8 | r;
			}

			m_buffer->vertex = *m_transformationBack * position;
			m_buffer->uv = uv[0];
			m_buffer->tid = ts;
			m_buffer->color = c;
			m_buffer++;

			m_buffer->vertex = *m_transformationBack * Maths::vec3(position.x, position.y + size.y, position.z);
			m_buffer->uv = uv[1];
			m_buffer->tid = ts;
			m_buffer->color = c;
			m_buffer++;

			m_buffer->vertex = *m_transformationBack * Maths::vec3(position.x + size.x, position.y + size.y, position.z);
			m_buffer->uv = uv[2];
			m_buffer->tid = ts;
			m_buffer->color = c;
			m_buffer++;

			m_buffer->vertex = *m_transformationBack * Maths::vec3(position.x + size.x, position.y, position.z);
			m_buffer->uv = uv[3];
			m_buffer->tid = ts;
			m_buffer->color = c;
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
			for (size_t i{ 0 }; i < m_textureSlots.size(); ++i) {
				glActiveTexture(GL_TEXTURE0 + i);
				glBindTexture(GL_TEXTURE_2D, m_textureSlots[i]);
			}

			glBindVertexArray(m_vao);
			m_ibo->bind();

			glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, 0);

			m_ibo->unbind();
			glBindVertexArray(0);

			m_indexCount = 0;
		}

	}
}