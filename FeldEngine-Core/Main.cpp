#include "graphics\window.h"
#include "maths\math.h"

int main()
{

	Fd::Graphics::Window window("FeldEngine", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao{};
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	Fd::Maths::Matrix4 position{ Fd::Maths::Matrix4::translation(Fd::Maths::Vector3<float>(2, 3, 4)) };
	position *= Fd::Maths::Matrix4::identity();

	while (!window.closed()) {
		//std::cout << window.getWidth() << ", " << window.getHeight() << std::endl;
		window.clear();

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