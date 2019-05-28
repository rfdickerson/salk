//
//  component.hpp
//  Hodhr
//
//  Created by Robert F. Dickerson on 5/24/19.
//  Copyright © 2019 Robert F. Dickerson. All rights reserved.
//

#ifndef component_hpp
#define component_hpp

#include <stdio.h>

//#include "../graphics/renderer.h"

namespace hodhr {
  
  namespace graphics {
    class Renderer;
  }
  
namespace core {

class Actor;
  
class Component {
public:
  Component();
  virtual ~Component();
  
  virtual void Init() = 0;
  virtual void Update(float dt);
  virtual void Draw(graphics::Renderer * renderer);
  
  void Attach(Actor *actor);
  
protected:
  Actor * parent_;
  
};
  
}
}

#endif /* component_hpp */
