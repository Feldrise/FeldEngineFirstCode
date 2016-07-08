#pragma once

#include <deque>

#include "Renderer2D.h"
#include "StaticSprite.h"

namespace Fd {
	namespace Graphics {

		class SimpleRenderer2D : Renderer2D
		{
		public:
			virtual void submit(const Renderable2D* renderable) override;
			virtual void flush() override;

		private:
			std::deque<const StaticSprite*> m_renderQueue;
		};

	}
}
