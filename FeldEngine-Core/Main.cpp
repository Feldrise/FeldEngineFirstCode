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
#include <string>

#include "src/Graphics/Window.h"
#include "src/Maths/Math.h"
#include "src/Utils/Timer.h"

#include "src/Graphics/Label.h"
#include "src/Graphics/Shader.h"
#include "src/Graphics/Renderable2D.h"
#include "src/Graphics/sprite.h"
#include "src/Graphics/StaticSprite.h"
#include "src/Graphics/BatchRenderer2D.h"
#include "src/Graphics/SimpleRenderer2D.h"
#include "src/Graphics/Layers/TileLayer.h"
#include "src/Graphics/Layers/Group.h"
#include "src/Graphics/Texture.h"

int main()
{
	Fd::Graphics::Window window("FeldEngine demo", 960, 540);

	bool teste50KSprites{ false };

	Fd::Maths::mat4 ortho{ Fd::Maths::mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f) };

	Fd::Graphics::Shader *shader = new Fd::Graphics::Shader("src/Shaders/basic.vert", "src/Shaders/basic.frag");

	GLint texIDs[] =
	{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	};

	shader->enable();
	shader->setUniform2f("light_pos", Fd::Maths::vec2(4.0f, 1.5f));
	shader->setUniform4f("colour", Fd::Maths::vec4(0.4f, 0.7f, 0.6f, 1.0f));

	Fd::Graphics::TileLayer layer{ shader };
	
	Fd::Graphics::Texture* textures[] =
	{
		new Fd::Graphics::Texture("ta.png"),
		new Fd::Graphics::Texture("tb.png"),
		new Fd::Graphics::Texture("tc.png")
	};

	for (float y = -9.0f; y < 9.0f; ++y)
	{
		for (float x = -16.0f; x < 16.0f; ++x)
		{
			//			layer.add(new Fd::Graphics::Sprite(x, y, 0.9f, 0.9f, Fd::Maths::vec4(1, rand() % 1000 / 1000.0f, 0, 1)));
			int r{ rand() % 256 };
			int col{ 0xff0000 << 8 | r };
			if (rand() % 4 == 0)
				layer.add(new Fd::Graphics::Sprite(x, y, 0.9f, 0.9f, col));
			else
				layer.add(new Fd::Graphics::Sprite(x, y, 0.9f, 0.9f, textures[rand() % 3]));
		}
	}

	Fd::Graphics::Group* g{ new Fd::Graphics::Group(Fd::Maths::mat4::translation(Fd::Maths::vec3(-15.8f, 7.0f, 0.0f))) };
	Fd::Graphics::Label* hello{ new Fd::Graphics::Label("Hello World!", 0.4f, 0.4f, 0xffffffff) };
	g->add(new Fd::Graphics::Sprite(0.0f, 0.0f, 6.6f, 1.5f, 0x00ff00DD));
	g->add(hello);

	layer.add(g);

	shader->enable();
	shader->setUniform1iv("textures", texIDs, 10);
	shader->setUniformMat4("pr_matrix", Fd::Maths::mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));
	Fd::Timer time;
	float timer{};
	unsigned frames{ 0 };

	while (!window.closed()) {
		window.clear();


		double x, y;
		window.getMousePosition(x, y);
		shader->setUniform2f("light_pos", Fd::Maths::vec2(static_cast<float>((x * 32.0f / window.getWidth() - 16.0f)), static_cast<float>((9.0f - y * 18.0f / window.getHeight()))));
		layer.render();

		window.update();
		++frames;
		if (time.elapsed() - timer > 1.0f) {
			timer += 1.0f;
			window.setTitle(std::string("FeldEngine demo - " + std::to_string(frames) + " FPS").c_str());
			frames = 0;
		}
	}

	for (int i{ 0 }; i < 3; ++i) {
		delete textures[i];
	}
	return 0;
}
