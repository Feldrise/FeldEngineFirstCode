#pragma once

#include <GL/glew.h>

#include "../Maths/Math.h"
#include "Renderable2D.h"

namespace Fd {
	namespace Graphics {

		class Renderer2D
		{
		public:
			virtual void submit(const Renderable2D* renderable) = 0;
			virtual void flush() = 0;
		};

	}
}
