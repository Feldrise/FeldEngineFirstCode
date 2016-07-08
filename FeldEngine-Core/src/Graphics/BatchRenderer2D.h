#pragma once

#include "Renderer2D.h"
#include "Buffers/IndexBuffer.h"

namespace Fd {
	namespace Graphics {
		
		const int RENDERER_MAX_SPRITE = 60000;
		const int RENDERER_INDICES_SIZE = RENDERER_MAX_SPRITE * 6;
		const float RENDERER_VERTEX_SIZE = sizeof(VertexData);
		const float RENDERER_SPRITE_SIZE = RENDERER_VERTEX_SIZE * 4;
		const float RENDERER_BUFFER_SIZE = RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITE;

		const unsigned SHADER_VERTEX_INDEX = 0;
		const unsigned SHADER_COLOR_INDEX = 1;

		class BatchRenderer2D : Renderer2D
		{
		public:
			BatchRenderer2D();
			~BatchRenderer2D();

			void begin();
			virtual void submit(const Renderable2D* renderable) override;
			void end();
			virtual void flush() override;

		private:
			GLuint m_vao;
			GLuint m_vbo;
			IndexBuffer* m_ibo;
			GLsizei m_indexCount;
			VertexData* m_buffer;
		};

	}
}