//
//  shader.cpp
//  Hodhr
//
//  Created by Robert F. Dickerson on 5/26/19.
//  Copyright © 2019 Robert F. Dickerson. All rights reserved.
//

#include "shader.h"

#include <iostream>
#include <fstream>

namespace hodhr {
  namespace graphics {
    
    
    std::string loadFile(const std::string & filename)
    {
      std::ifstream in(filename.c_str(), std::ios::in | std::ios::binary);
      
      if (in)
      {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        
        return (contents);
      }
      
      throw(errno);
    }
    
    Shader* Shader::BuildShader(std::string vertex_shader, std::string fragment_shader) {
      Shader * shader = new Shader();
      
      char logInfo[256];
      
      std::string shader_src = loadFile(vertex_shader);
      const char *c_str = shader_src.c_str();
      GLuint vsid = glCreateShader(GL_VERTEX_SHADER);
      glShaderSource(vsid, 1, &c_str, NULL);
      glCompileShader(vsid);
      
      glGetShaderInfoLog(vsid, 256, NULL, logInfo);
      std::cout << "Compiled Shader " << vertex_shader << logInfo << std::endl;
      
      shader_src = loadFile(fragment_shader);
      const char *cf_str = shader_src.c_str();
      GLuint fsid = glCreateShader(GL_FRAGMENT_SHADER);
      glShaderSource(fsid, 1, &cf_str, NULL);
      glCompileShader(fsid);
      
      glGetShaderInfoLog(fsid, 256, NULL, logInfo);
      std::cout << "Compiled Shader:" << fragment_shader << logInfo << std::endl;
      
      GLuint program_id = glCreateProgram();
      glAttachShader(program_id, vsid);
      glAttachShader(program_id, fsid);
      
      glLinkProgram(program_id);
      
      glGetProgramInfoLog(program_id, 256, NULL, logInfo);
      
      std::cout << "Compilation result: \n" << logInfo << std::endl;
      
      GLint success = GL_FALSE;
      glGetProgramiv(program_id, GL_LINK_STATUS, &success);
      
      if (success == GL_FALSE) {
        std::cerr << "Error linking shader" << std::endl;
        exit(1);
      }
      
      glDetachShader(program_id, vsid);
      glDetachShader(program_id, fsid);
      
      glDeleteShader(vsid);
      glDeleteShader(fsid);
      
      shader->program_id_ = program_id;
      
      return shader;
    }
    
    Shader::Shader() {}
    
    Shader::~Shader() {
      glDeleteShader(program_id_);
    }
    
    GLuint Shader::UniformLocation(const std::string name) const {
      return glGetUniformLocation(program_id_, name.c_str());
    }
    
    void Shader::Use() const {
      glUseProgram(program_id_);
    }
    
  }
}
