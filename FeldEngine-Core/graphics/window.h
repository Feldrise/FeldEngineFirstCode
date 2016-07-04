#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

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
		void update() const;
		bool closed() const;

		bool m_keys[MAX_KEYS];
		bool m_mouseButtons[MAX_BUTTONS];
		double mx;
		double my;

		bool isKeyPressed(unsigned keyCode) const;
		bool isMouseButtonPressed(unsigned button) const;
		void getMousePosition(double& x, double& y) const; // Will return a Vector2

		inline int getWidth() const { return m_width; }
		inline int getHeight() const { return m_height; }
	private:
		// Private Function
		friend static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
		friend static void mouseButton_callback(GLFWwindow *window, int button, int action, int mods);
		friend static void cursorPosition_callback(GLFWwindow *window, double xpos, double ypos);

		// Private members
		const char *m_title;

		int m_width;
		int m_height;
		bool m_closed;

		GLFWwindow *m_window;

	};

	}
}