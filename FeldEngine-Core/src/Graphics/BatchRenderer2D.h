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

#pragma once

#include <cstddef>

#include "Renderer2D.h"
#include "Renderable2D.h"
#include "Buffers/IndexBuffer.h"

#include "../../../deps/src/Freetype-gl/freetype-gl.h"

namespace Fd {
	namespace Graphics {
		
		const int RENDERER_MAX_SPRITE = 60000;
		const int RENDERER_INDICES_SIZE = RENDERER_MAX_SPRITE * 6;
		const float RENDERER_VERTEX_SIZE = sizeof(VertexData);
		const float RENDERER_SPRITE_SIZE = RENDERER_VERTEX_SIZE * 4;
		const float RENDERER_BUFFER_SIZE = RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITE;

		const unsigned SHADER_VERTEX_INDEX = 0;
		const unsigned SHADER_UV_INDEX = 1;
		const unsigned SHADER_TID_INDEX = 2;
		const unsigned SHADER_COLOR_INDEX = 3;

		class BatchRenderer2D : public Renderer2D
		{
		public:
			BatchRenderer2D();
			~BatchRenderer2D();

			void begin() override;
			virtual void submit(const Renderable2D* renderable) override;
			virtual void drawString(const std::string& text, const Maths::vec3& position, unsigned int color) override;
			void end() override;
			virtual void flush() override;

		private:
			GLuint m_vao;
			GLuint m_vbo;
			IndexBuffer* m_ibo{ nullptr };
			GLsizei m_indexCount;
			VertexData* m_buffer{ nullptr };

			std::vector<GLuint> m_textureSlots;
			ftgl::texture_atlas_t* m_FTAtlas{ nullptr };
			ftgl::texture_font_t* m_FTFont{ nullptr };
		};

	}
}