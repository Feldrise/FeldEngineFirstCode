#pragma once

#include <GL/glew.h>

namespace Fd {
	namespace Graphics {

		class IndexBuffer
		{
		public:
			IndexBuffer(GLushort *data, GLsizei count);
			IndexBuffer(GLuint *data, GLsizei count);
			~IndexBuffer();

			void bind() const;
			void unbind() const;

			inline GLuint getCount() const { return m_count; }

		private:
			GLuint m_bufferID;
			GLuint m_count;

		};

	}
}