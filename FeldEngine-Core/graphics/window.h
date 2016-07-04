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
		void update() const;
		bool closed() const;

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
		std::array<bool, MAX_KEYS> m_keys{};
		std::array<bool, MAX_BUTTONS> m_mouseButtons{};
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