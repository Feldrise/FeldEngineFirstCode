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

#include <GL/glew.h>

#include "../Maths/Math.h"
#include "Renderer2D.h"
#include "Buffers/Buffer.h"
#include "Buffers/IndexBuffer.h"
#include "Buffers/VertexArray.h"
#include "Shader.h"
#include "Texture.h"

namespace Fd {
	namespace Graphics {

		struct VertexData
		{
			Maths::vec3 vertex;
			Maths::vec2 uv;
			float tid;
			unsigned color;
		};

		class Renderable2D 
		{
		public:
			// Protected functions
			Renderable2D(Maths::vec3 position, Maths::vec2 size, unsigned int color) :
				m_position(position), 
				m_size(size), 
				m_color(color),
				m_texture(nullptr)
			{
				setUVDefaults();
			}

			~Renderable2D() { }

			virtual void submit(Renderer2D *renderer) const {
				renderer->submit(this);
			}

			void setColor(unsigned int color) { m_color = color; }
			void setColor(const Maths::vec4& color) {
				int r{ static_cast<int>(color.x * 255.0f) };
				int g{ static_cast<int>(color.y * 255.0f) };
				int b{ static_cast<int>(color.z * 255.0f) };
				int a{ static_cast<int>(color.w * 255.0f) };

				m_color = a << 24 | b << 16 | g << 8 | r;
			}

			inline const Maths::vec3& getPosition() const { return m_position; }
			inline const Maths::vec2& getSize() const { return m_size; }
			inline const unsigned int getColor() const { return m_color; }
			inline const std::vector<Maths::vec2>& getUV() const { return m_uv; }

			inline const GLuint getTID() const { return m_texture ? m_texture->getID() : 0; }

		protected:
			Renderable2D() : m_texture(nullptr) { setUVDefaults(); }

			Maths::vec3 m_position;
			Maths::vec2 m_size;
			unsigned int m_color;
			std::vector<Maths::vec2> m_uv;

			Texture* m_texture;

		private:
			void setUVDefaults() {
				m_uv.push_back(Maths::vec2(0, 0));
				m_uv.push_back(Maths::vec2(0, 1));
				m_uv.push_back(Maths::vec2(1, 1));
				m_uv.push_back(Maths::vec2(1, 0));
			}

		};

	}
}
