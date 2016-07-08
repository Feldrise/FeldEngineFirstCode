#include "VertexArray.h"

namespace Fd {
	namespace Graphics {



		VertexArray::VertexArray()
		{
			glGenVertexArrays(1, &m_arrayID);
		}

		VertexArray::~VertexArray()
		{
			for (size_t i{ 0 }; i < m_buffers.size(); i++) {
				delete m_buffers[i];
			}

			glDeleteVertexArrays(1, &m_arrayID);
		}

		void VertexArray::addBuffer(Buffer * buffer, GLuint index)
		{
			bind();
			buffer->bind();

			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

			buffer->unbind();
			unbind();
		}

		void VertexArray::bind()
		{
			glBindVertexArray(m_arrayID);
		}

		void VertexArray::unbind()
		{
			glBindVertexArray(0);
		}

	}
}
