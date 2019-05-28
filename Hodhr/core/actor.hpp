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

#include "component.hpp"

namespace hodhr {
namespace core {
    
class Actor {
public:
  Actor();
  ~Actor();
  
  glm::vec3 Position() const;
  
  void Init();
  void Update(float dt);
  void Attach(Component * component);
  
  std::vector<Component*> Components() const;
  
private:
  
  glm::vec3 position_;
  
  std::string name_;
  
  std::vector<Component*> components_;
};
    
}
}

#endif /* actor_hpp */
