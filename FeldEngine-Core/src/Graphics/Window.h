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
#include <GLFW/glfw3.h>
#include <iostream>
#include <array>

namespace Fd { 
	namespace Graphics {

	const int MAX_KEYS = 1024;
	const int MAX_BUTTONS = 32;

	class Window
	{
	public:
		Window(const char *title, int width, int height);
		~Window();

		void clear() const;
		void update();
		bool closed() const;

		bool isKeyPressed(unsigned keyCode) const;
		bool isKeyTyped(unsigned keyCode) const;
		bool isMouseButtonPressed(unsigned button) const;
		bool isMouseButtonClicked(unsigned button) const;
		void getMousePosition(double& x, double& y) const; // Will return a Vector2

		inline int getWidth() const { return m_width; }
		inline int getHeight() const { return m_height; }

		void setTitle(const char *title) {
			m_title = title;
			glfwSetWindowTitle(m_window, title);
		}
	private:
		// Private Function
		friend static void window_resize(GLFWwindow *window, int width, int height);
		friend static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
		friend static void mouseButton_callback(GLFWwindow *window, int button, int action, int mods);
		friend static void cursorPosition_callback(GLFWwindow *window, double xpos, double ypos);

		// Private members
		std::array<bool, MAX_BUTTONS> m_mouseButtons{};
		std::array<bool, MAX_BUTTONS> m_mouseState{};
		std::array<bool, MAX_BUTTONS> m_mouseClicked{};
		std::array<bool, MAX_KEYS> m_keys{};
		std::array<bool, MAX_KEYS> m_keyState{};
		std::array<bool, MAX_KEYS> m_keyTyped{};
		double mx{};
		double my{};

		const char *m_title{ "FeldEngine game" };

		int m_width{ 1024};
		int m_height{ 768 };
		bool m_closed{ false };

		GLFWwindow *m_window{ nullptr };

	};

	}
}