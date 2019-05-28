//
//  camera_component.hpp
//  Hodhr
//
//  Created by Robert F. Dickerson on 5/27/19.
//  Copyright © 2019 Robert F. Dickerson. All rights reserved.
//

#ifndef camera_component_hpp
#define camera_component_hpp

#include "../core/component.hpp"

#include <stdio.h>

#include <GL/glew.h>
#include <glm/glm.hpp>

namespace hodhr {
  namespace graphics {
    class CameraComponent: public core::Component {
    public:
      CameraComponent();
      ~CameraComponent();
      
      void Init();
      void Update(float dt);
      
      glm::mat4 ModelViewMatrix() const;
      
    private:
      
      GLfloat near_;
      GLfloat far_;
      
      GLfloat field_of_view_;
      GLfloat aspect_ratio_;
      
      glm::mat4 projection_matrix_;
      glm::mat4 view_matrix_;
      
      glm::vec3 direction_;
      glm::vec3 up_;
      glm::vec3 right_;
      
      GLfloat horizontal_angle_;
      GLfloat vertical_angle_;
      
    };
  }
}

#endif /* camera_component_hpp */