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
#include <vector>

#include "../Maths/Math.h"


namespace Fd {
	namespace Graphics {

		class Renderable2D;
		
		class Renderer2D
		{
		public:
			void push(const Maths::mat4& matrix, bool override = false) {
				if(override)
					m_transformationStack.push_back(matrix);
				else
					m_transformationStack.push_back(m_transformationStack.back() * matrix);

				m_transformationBack = &m_transformationStack.back();
			}
			void pop() {
				if(m_transformationStack.size() > 1)
					m_transformationStack.pop_back();

				m_transformationBack = &m_transformationStack.back();
			}

			virtual void begin() {}
			virtual void submit(const Renderable2D* renderable) = 0;
			virtual void end() {}
			virtual void flush() = 0;

		protected:
			Renderer2D() {
				m_transformationStack.push_back(Maths::mat4::identity());
				m_transformationBack = &m_transformationStack.back();
			}

			std::vector<Maths::mat4> m_transformationStack;
			Maths::mat4* m_transformationBack;
		};

	}
}
