//
//  engine.hpp
//  Hodhr
//
//  Created by Robert F. Dickerson on 5/22/19.
//  Copyright © 2019 Robert F. Dickerson. All rights reserved.
//

#ifndef engine_hpp
#define engine_hpp

#include <stdio.h>

#include "../graphics/renderer.h"
#include "scene.hpp"

namespace hodhr {
namespace core {
        
class Engine {
 public:
  Engine();
  ~Engine();
    
  void Start();
    
 private:
  void Run();
  void HandleUserInput(float dt);
    
  graphics::Renderer renderer_;
  Scene scene_;
  
  bool done_;
  
    
};
        
} // namespace core
} // namespace hodhr

#endif /* engine_hpp */
