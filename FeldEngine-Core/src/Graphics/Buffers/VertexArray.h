#pragma once

#include <GL/glew.h>
#include <vector>

#include "Buffer.h"

namespace Fd {
	namespace Graphics {

		class VertexArray
		{
		public:
			VertexArray();
			~VertexArray();
			
			void addBuffer(Buffer *buffer, GLuint index);

			void bind();
			void unbind();

		private:
			GLuint m_arrayID;
			std::vector<Buffer*> m_buffers;
		};

	}
}