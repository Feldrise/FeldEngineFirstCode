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

#include "shader.h"  
   
 namespace Fd { 
	 namespace Graphics {  
   
 		Shader::Shader(const char* vertPath, const char* fragPath) :
			m_vertPath(vertPath), 
			m_fragPath(fragPath)  
 		{  
 			m_shaderID = load();  
 		}  
   
 		Shader::~Shader()  
 		{  
 			glDeleteProgram(m_shaderID);  
 		}  
   
 		GLuint Shader::load()  
 		{  
 			GLuint program = glCreateProgram();  
 			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);  
 			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);  
   
 			std::string vertSourceString = UtilsFile::read_file(m_vertPath);  
 			std::string fragSourceString = UtilsFile::read_file(m_fragPath);
   
 			const char* vertSource = vertSourceString.c_str();  
 			const char* fragSource = fragSourceString.c_str();  
   
 			glShaderSource(vertex, 1, &vertSource, NULL);  
 			glCompileShader(vertex);  
   
 			GLint result;  
 			glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);  
 			if (result == GL_FALSE)  
 			{  
 				GLint length;  
 				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);  
 				std::vector<char> error(length);  
 				glGetShaderInfoLog(vertex, length, &length, &error[0]);  
 				std::cout << "Failed to compile vertex shader!" << std::endl << &error[0] << std::endl;  
 				glDeleteShader(vertex);  
 				return 0;  
 			}  
   
 			glShaderSource(fragment, 1, &fragSource, NULL);  
 			glCompileShader(fragment);  
   
 			glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);  
 			if (result == GL_FALSE)  
 			{  
 				GLint length;  
 				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);  
 				std::vector<char> error(length);  
 				glGetShaderInfoLog(fragment, length, &length, &error[0]);  
 				std::cout << "Failed to compile fragment shader!" << std::endl << &error[0] << std::endl;  
 				glDeleteShader(fragment);  
 				return 0;  
 			}  
   
 			glAttachShader(program, vertex);  
 			glAttachShader(program, fragment);  
   
 			glLinkProgram(program);  
 			glValidateProgram(program);  
   
 			glDeleteShader(vertex);  
 			glDeleteShader(fragment);  
   
 			return program;  
 		}  
   
 		GLint Shader::getUniformLocation(const GLchar* name)  
 		{  
 			return glGetUniformLocation(m_shaderID, name);  
 		}  
   
 		void Shader::setUniform1f(const GLchar* name, float value)  
 		{  
 			glUniform1f(getUniformLocation(name), value);  
 		}  
   
 		void Shader::setUniform1i(const GLchar* name, int value)  
 		{  
 			glUniform1i(getUniformLocation(name), value);  
 		}  
   
 		void Shader::setUniform2f(const GLchar* name, const Maths::Vector2<float>& vector)
 		{  
 			glUniform2f(getUniformLocation(name), vector.x, vector.y);  
 		}  
   
 		void Shader::setUniform3f(const GLchar* name, const Maths::Vector3<float>& vector)
 		{  
 			glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);  
 		}  
   
 		void Shader::setUniform4f(const GLchar* name, const Maths::Vector4<float>& vector)
 		{  
 			glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);  
 		}  
   
 		void Shader::setUniformMat4(const GLchar* name, const Maths::mat4& matrix)  
 		{  
 			glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.elements);  
 		}  
   
 		void Shader::enable() const  
 		{  
 			glUseProgram(m_shaderID);  
 		}  
   
 		void Shader::disable() const  
 		{  
 			glUseProgram(0);  
 		}  
   } 
} 
