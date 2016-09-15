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

#include "window.h"

namespace Fd {
	namespace Graphics {

		Window::Window(const char * title, int width, int height) : 
			m_title(title),
			m_width(width), 
			m_height(height)
		{
			if (!glfwInit()) {
				glfwTerminate();
				std::cout << "Failed to init GLFW" << std::endl;
				return;
			}

			m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);
			if (!m_window) {
				glfwTerminate();
				std::cout << "Failed to create the Window" << std::endl;
				return;
			}

			glfwMakeContextCurrent(m_window);
			glfwSetWindowUserPointer(m_window, this);
			glfwSetFramebufferSizeCallback(m_window, window_resize);
			glfwSetKeyCallback(m_window, key_callback);
			glfwSetMouseButtonCallback(m_window, mouseButton_callback);
			glfwSetCursorPosCallback(m_window, cursorPosition_callback);
			glfwSwapInterval(0.0);

			if (glewInit() != GLEW_OK) {
				glfwTerminate();
				std::cout << "Failed to init GLEW" << std::endl;
				return;
			}

			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			std::cout << "**********Feld[2D]Engine**********" << std::endl;
			std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;
			std::cout << "**********************************" << std::endl;
			std::cout << std::endl;

			for (int i{ 0 }; i < MAX_KEYS; i++) {
				m_keys[i] = false;
			}

			for (int i{ 0 }; i < MAX_BUTTONS; i++) {
				m_mouseButtons[i] = false;
			}


		}

		Window::~Window()
		{
			glfwTerminate();
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update() const
		{
			GLenum error = glGetError();

			if (error != GL_NO_ERROR)
				std::cout << "OpenGL error: " << error << std::endl;

			glfwSwapBuffers(m_window);
			glfwPollEvents();
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_window) == 1;
		}

		bool Window::isKeyPressed(unsigned keyCode) const
		{
			if (keyCode >= MAX_KEYS)
				return false;

			return m_keys[keyCode];
		}

		bool Window::isMouseButtonPressed(unsigned button) const
		{
			if (button >= MAX_BUTTONS)
				return false;

			return m_mouseButtons[button];
		}

		void Window::getMousePosition(double & x, double & y) const
		{
			x = mx;
			y = my;
		}

		void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
		{
			Window *win = static_cast<Window*>(glfwGetWindowUserPointer(window));
			win->m_keys[key] = action != GLFW_RELEASE;
		}

		void mouseButton_callback(GLFWwindow * window, int button, int action, int mods)
		{
			Window *win = static_cast<Window*>(glfwGetWindowUserPointer(window));
			win->m_mouseButtons[button] = action != GLFW_RELEASE;
		}

		void cursorPosition_callback(GLFWwindow * window, double xpos, double ypos)
		{
			Window *win = static_cast<Window*>(glfwGetWindowUserPointer(window));
			win->mx = xpos;
			win->my = ypos;
		}

		void window_resize(GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);
			Window *win = static_cast<Window*>(glfwGetWindowUserPointer(window));
			win->m_width = width;
			win->m_height = height;
		}
	}
}