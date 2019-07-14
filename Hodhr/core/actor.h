//
//  actor.hpp
//  Hodhr
//
//  Created by Robert F. Dickerson on 5/24/19.
//  Copyright © 2019 Robert F. Dickerson. All rights reserved.
//

#ifndef actor_hpp
#define actor_hpp

#include <string>
#include <vector>
#include <stdio.h>

#include "glm/glm.hpp"

#include "component.h"
#include "event.h"

namespace hodhr {
namespace core {
    
class Actor {
public:
  Actor();
  ~Actor();

  void Init();
  void Update(float dt);
  void Attach(Component * component);
  
  std::vector<Component*> Components() const;
  
  std::string Name() const; 

  glm::mat4 ModelMatrix() const;
  glm::vec3 Direction() const;
  glm::vec3 Up() const;
  glm::vec3 Right() const;

  void SetPosition(glm::vec3 position);
  glm::vec3 Position() const;

  void SetHorizontalAngle(float angle);
  void SetVerticalAngle(float angle);

  
private:

  void UpdateDirections();
  
  glm::vec3 position_;
  
  std::string name_;
  
  std::vector<Component*> components_;

  glm::vec3 direction_;
  glm::vec3 up_;
  glm::vec3 right_;

  float horizontal_angle_;
  float vertical_angle_;

};
    
}
}

#endif /* actor_hpp */
