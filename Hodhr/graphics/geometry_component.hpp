//
//  geometry_component.hpp
//  Hodhr
//
//  Created by Robert F. Dickerson on 5/24/19.
//  Copyright © 2019 Robert F. Dickerson. All rights reserved.
//

#ifndef geometry_component_hpp
#define geometry_component_hpp

#include <stdio.h>

#include <GL/glew.h>

#include "../core/component.hpp"

namespace hodhr {
namespace graphics {

class GeometryComponent: public core::Component {
public:
  
  ~GeometryComponent();
  
  void Init();
  
  void Draw(graphics::Renderer * renderer);
//  virtual void Update(float dt);
  
private:
  
  GLuint vertex_array;
  GLuint vertex_buffer;
  
};
    
}
}

#endif /* geometry_component_hpp */
