#include "graphics\window.h"
#include "maths\math.h"

int main()
{

	Fd::Graphics::Window window("FeldEngine", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao{};
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	Fd::Maths::Matrix4<float> position{ Fd::Maths::Matrix4<float>::translation(Fd::Maths::Vector3<float>(2, 3, 4)) };
	position *= Fd::Maths::Matrix4<float>::identity();

	position.elements[12] = 2.0f;

	Fd::Maths::Vector4<float> column = position.columns[3];

	std::cout << &position.elements[12] << std::endl;
	std::cout << &position.columns[3].x << std::endl;

	while (!window.closed()) {
		//std::cout << window.getWidth() << ", " << window.getHeight() << std::endl;
		window.clear();
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