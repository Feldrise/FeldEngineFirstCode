#pragma once

#include <GL/glew.h>

namespace Fd {
	namespace Graphics {

		class Buffer
		{
		public:
			Buffer(GLfloat *data, GLsizei count, GLuint componentCount);
			~Buffer();

			void bind() const;
			void unbind() const;

			inline GLuint getComponentCount() const { return m_componentCount; }

		private:
			GLuint m_bufferID;
			GLuint m_componentCount;

		};

	}
}