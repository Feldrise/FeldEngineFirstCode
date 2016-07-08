#pragma once

#include <GL/glew.h>

#include "../Maths/Math.h"
#include "Buffers/Buffer.h"
#include "Buffers/IndexBuffer.h"
#include "Buffers/VertexArray.h"
#include "Shader.h"

namespace Fd {
	namespace Graphics {

		struct VertexData
		{
			Maths::vec3 vertex;
			Maths::vec4 color;
		};

		class Renderable2D 
		{
		public:
			// Protected functions
			Renderable2D(Maths::vec3 position, Maths::vec2 size, Maths::vec4 color) 
				: m_position(position), m_size(size), m_color(color)
			{

			}

			~Renderable2D() { }

			inline const Maths::vec3& getPosition() const { return m_position; }
			inline const Maths::vec2& getSize() const { return m_size; }
			inline const Maths::vec4& getColor() const { return m_color; }

		protected:
			Maths::vec3 m_position;
			Maths::vec2 m_size;
			Maths::vec4 m_color;

		private:


		};

	}
}
