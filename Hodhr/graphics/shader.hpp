//
//  shader.hpp
//  Hodhr
//
//  Created by Robert F. Dickerson on 5/26/19.
//  Copyright © 2019 Robert F. Dickerson. All rights reserved.
//

#ifndef shader_hpp
#define shader_hpp

#include <stdio.h>

#include <string>

#include <GL/glew.h>

namespace hodhr {
  namespace graphics {
    class Shader {
    public:

      static Shader* BuildShader(std::string vertex_shader, std::string fragment_shader);
      
      GLuint UniformLocation(const std::string name);
      
      ~Shader();
      
      void Use();
      
    private:
      
      Shader();
      // opengl program id
      GLuint program_id_;
      
    };
  }
}

#endif /* shader_hpp */
