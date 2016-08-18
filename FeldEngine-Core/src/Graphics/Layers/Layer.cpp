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


#include "Layer.h"

namespace Fd {
	namespace Graphics {

		Layer::Layer(Renderer2D *renderer, Shader *shader, Maths::mat4 projectionMatrix) :
			m_renderer(renderer),
			m_shader(shader),
			m_projectionMatrix(projectionMatrix)
		{
			m_shader->enable();
			m_shader->setUniformMat4("pr_matrix", m_projectionMatrix);
			m_shader->disable();
		}

		Layer::~Layer()
		{
			delete m_shader;
			delete m_renderer;
			for (int i{ 0 }; i < m_renderables.size(); ++i)
				delete m_renderables[i];
		}

		void Layer::add(Renderable2D * renderable)
		{
			m_renderables.push_back(renderable);
		}

		void Layer::render()
		{
			m_shader->enable();

			m_renderer->begin();
			for (const Renderable2D *renderable : m_renderables)
				m_renderer->submit(renderable);
			m_renderer->end();

			m_renderer->flush();
		}

	}
}