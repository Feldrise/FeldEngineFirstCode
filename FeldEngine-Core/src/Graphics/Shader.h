#pragma once  
   
 #include <iostream>  
 #include <vector>  
 #include <GL/glew.h>  
   
#include "../Maths/Math.h"
#include "../Utils/UtilsFile.h"
   
 namespace Fd { 
	 namespace Graphics {  
   
 	class Shader  
 	{  
 	private:  
 		GLuint m_ShaderID;  
 		const char* m_VertPath;  
 		const char* m_FragPath;  
 	public:  
 		Shader(const char* vertPath, const char* fragPath);  
 		~Shader();  
   
   
 		void setUniform1f(const GLchar* name, float value);  
 		void setUniform1i(const GLchar* name, int value);  
 		void setUniform2f(const GLchar* name, const Maths::Vector2<float>& vector);  
 		void setUniform3f(const GLchar* name, const Maths::Vector3<float>& vector);
 		void setUniform4f(const GLchar* name, const Maths::Vector4<float>& vector);
 		void setUniformMat4(const GLchar* name, const Maths::mat4& matrix);  
   
 		void enable() const;  
 		void disable() const;  
 	private:  
 		GLuint load();  
 		GLint getUniformLocation(const GLchar* name);  
 	};  
   
 } } 
