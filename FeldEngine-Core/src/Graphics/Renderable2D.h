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
#include "Buffers/Buffer.h"
#include "Buffers/IndexBuffer.h"
#include "Buffers/VertexArray.h"
#include "Shader.h"

namespace Fd {
	namespace Graphics {

		struct VertexData
		{
			Maths::vec3 vertex;
			// Maths::vec4 color;
			unsigned color;
		};

		class Renderable2D 
		{
		public:
			// Protected functions
			Renderable2D(Maths::vec3 position, Maths::vec2 size, Maths::vec4 color) 
				: m_position(position), m_size(size), m_color(color)
			{

			}

			~Renderable2D() { }

			inline const Maths::vec3& getPosition() const { return m_position; }
			inline const Maths::vec2& getSize() const { return m_size; }
			inline const Maths::vec4& getColor() const { return m_color; }

		protected:
			Maths::vec3 m_position;
			Maths::vec2 m_size;
			Maths::vec4 m_color;

		private:


		};

	}
}