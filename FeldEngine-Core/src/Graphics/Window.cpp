#include "window.h"

namespace Fd {
	namespace Graphics {

		void window_resize(GLFWwindow *window, int width, int height);

		Window::Window(const char * title, int width, int height) : m_title(title), m_width(width), m_height(height)
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
			glfwSetWindowSizeCallback(m_window, window_resize);
			glfwSetKeyCallback(m_window, key_callback);
			glfwSetMouseButtonCallback(m_window, mouseButton_callback);
			glfwSetCursorPosCallback(m_window, cursorPosition_callback);

			if (glewInit() != GLEW_OK) {
				glfwTerminate();
				std::cout << "Failed to init GLEW" << std::endl;
				return;
			}

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
		}
	}
}