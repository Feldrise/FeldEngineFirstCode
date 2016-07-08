#pragma once

#include "Renderable2D.h"

namespace Fd {
	namespace Graphics {


		class StaticSprite : public Renderable2D
		{
		public:
			StaticSprite(float x, float y, float width, float height, const Maths::vec4 color, Shader& shader);
			~StaticSprite();

			inline VertexArray* getVAO() const { return m_vertexArray; }
			inline const IndexBuffer* getIBO() const { return m_indexBuffer; }

			inline Shader& getShader() const { return m_shader; }


		private:
			VertexArray* m_vertexArray;
			IndexBuffer* m_indexBuffer;
			Shader& m_shader;
		};

	}
}