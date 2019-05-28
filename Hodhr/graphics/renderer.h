//
//  renderer.hpp
//  Hodhr
//
//  Created by Robert F. Dickerson on 5/22/19.
//  Copyright © 2019 Robert F. Dickerson. All rights reserved.
//

#ifndef renderer_hpp
#define renderer_hpp

#include <stdio.h>

#include "window.h"
#include "shader.hpp"

#include "../core/scene.hpp"

namespace hodhr {
  namespace graphics {
    
    class Renderer {
    public:
      Renderer();
      ~Renderer();
      
      void Init();
      void Draw(const core::Scene &scene);
      
    private:
      Window window_;
      
      Shader *physical_shader;
      
      GLuint vpMatrix;
      
    };
    
  }
}

#endif /* renderer_hpp */
