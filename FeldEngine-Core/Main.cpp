#include "graphics\window.h"
#include "maths\math.h"

int main()
{

	Fd::Graphics::Window window("FeldEngine", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao{};
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	Fd::Maths::Vector2<float> a{ 1.0f, 2.0f };
	Fd::Maths::Vector2<float> b{ 2.0f, 4.0f };

	Fd::Maths::Vector2<float> c{ a + b };

	while (!window.closed()) {
		//std::cout << window.getWidth() << ", " << window.getHeight() << std::endl;
		window.clear();

		std::cout << c << std::endl;
		std::cout << a << " + " << b << std::endl;
		std::cout << (a != b) << std::endl;

		double x, y;
		window.getMousePosition(x, y);
		std::cout << x << ", " << y << std::endl;

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();

		//glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		window.update();
	}

	return 0;
}