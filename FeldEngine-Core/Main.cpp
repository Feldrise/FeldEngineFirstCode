#include <array>

#include "src/Graphics/window.h"
#include "src/Graphics/Shader.h"


int main()
{

	Fd::Graphics::Window window("FeldEngine", 960, 540);

	GLfloat vertices[] =
	{
		0, 0, 0,
		8, 0, 0,
		0, 3, 0,
		0, 3, 0,
		8, 3, 0,
		8, 0, 0
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	Fd::Maths::mat4 ortho = Fd::Maths::mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Fd::Graphics::Shader shader("src/Shaders/basic.vert", "src/Shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", Fd::Maths::mat4::translation(Fd::Maths::vec3(4, 3, 0)));

	shader.setUniform2f("light_pos", Fd::Maths::vec2(4.0f, 1.5f));
	shader.setUniform4f("colour", Fd::Maths::vec4(0.2f, 0.3f, 0.8f, 1.0f));

	while (!window.closed())
	{
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", Fd::Maths::vec2(static_cast<float>((x * 16.0f / 960.0f)), static_cast<float>((9.0f - y * 9.0f / 540.0f))));
		glDrawArrays(GL_TRIANGLES, 0, 6);
		window.update();
	}


	return 0;
}