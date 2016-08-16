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

#include <vector>
#include <time.h>

#include "src/Graphics/Window.h"

#include "src/Graphics/Shader.h"
#include "src/Graphics/Renderable2D.h"
#include "src/Graphics/sprite.h"
#include "src/Graphics/StaticSprite.h"
#include "src/Graphics/BatchRenderer2D.h"
#include "src/Graphics/SimpleRenderer2D.h"

#include "src/Maths/Math.h"

#include "src/Utils/Timer.h"

int main() 
{
	srand(static_cast<int>(time(nullptr)));
	const bool renderBatch{ true };
	const bool miniRect{ true };

	Fd::Graphics::Window window("FeldEngine demo", 960, 540);

	Fd::Maths::mat4 ortho{ Fd::Maths::mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f) };

	Fd::Graphics::Shader shader("src/Shaders/basic.vert", "src/Shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);

	std::vector<Fd::Graphics::Renderable2D*> sprites{};

	if (miniRect) {
		for (float y{ 0 }; y < 9.0f; y += 0.05f) {
			for (float x{ 0 }; x < 16.0f; x += 0.05f) {
				if (renderBatch) {
					sprites.push_back(new Fd::Graphics::Sprite(x, y, 0.04f, 0.04f, Fd::Maths::vec4(0.0f, rand() % 1000 / 1000.0f, 1.0f, 1.0f)));
				}
				else {
					sprites.push_back(new Fd::Graphics::StaticSprite(x, y, 0.04f, 0.04f, Fd::Maths::vec4(0.0f, rand() % 1000 / 1000.0f, 1.0f, 1.0f), shader));
				}
			}
		}
	}
	else {
		for (float y{ 0 }; y < 9.0f; y++) {
			for (float x{ 0 }; x < 16.0f; x++) {
				if (renderBatch) {
					sprites.push_back(new Fd::Graphics::Sprite(x, y, 0.9f, 0.9f, Fd::Maths::vec4(0.0f, rand() % 1000 / 1000.0f, 1.0f, 1.0f)));
				}
				else {
					sprites.push_back(new Fd::Graphics::StaticSprite(x, y, 0.9f, 0.9f, Fd::Maths::vec4(0.0f, rand() % 1000 / 1000.0f, 1.0f, 1.0f), shader));
				}
			}
		}
	}

	Fd::Graphics::BatchRenderer2D bRenderer;
	Fd::Graphics::SimpleRenderer2D sRenderer;

	shader.setUniform2f("light_pos", Fd::Maths::vec2(4.0f, 1.5f));
	shader.setUniform4f("colour", Fd::Maths::vec4(0.4f, 0.7f, 0.6f, 1.0f));

	Fd::Timer time;
	float timer{};
	unsigned frames{ 0 };

	while (!window.closed()) {
		window.clear();

		Fd::Maths::mat4 mat{ Fd::Maths::mat4::translation(Fd::Maths::vec3(5, 5, 5)) };
		mat = mat * Fd::Maths::mat4::rotation(time.elapsed() * 50.0f, Fd::Maths::vec3(0, 0, 1));
		mat = mat * Fd::Maths::mat4::translation(Fd::Maths::vec3(-5, -5, -5));
		shader.setUniformMat4("ml_matrix", mat);

		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", Fd::Maths::vec2(static_cast<float>((x * 16.0f / 960.0f)), static_cast<float>((9.0f - y * 9.0f / 540.0f))));

		if (renderBatch) {
			bRenderer.begin();
			for (size_t i{ 0 }; i < sprites.size(); i++) {
				bRenderer.submit(sprites[i]);
			}
			bRenderer.end();
			bRenderer.flush();
		}
		else {
			for (size_t i{ 0 }; i < sprites.size(); i++) {
				sRenderer.submit(sprites[i]);
			}
			sRenderer.flush();
		}

		window.update();
		++frames;
		if (time.elapsed() - timer > 1.0f) {
			timer += 1.0f;
			std::cout << frames << " FPS" << std::endl;
			frames = 0;
		}
	}

	return 0;
}