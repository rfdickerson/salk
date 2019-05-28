//
//  component.cpp
//  Hodhr
//
//  Created by Robert F. Dickerson on 5/24/19.
//  Copyright © 2019 Robert F. Dickerson. All rights reserved.
//

#include "component.hpp"

namespace hodhr {
  namespace core {
    
    Component::Component() {}
    
    Component::~Component() {}
    
    void Component::Update(float dt) {
      
    }
    
    void Component::Attach(Actor * actor)
    {
      this->parent_ = actor;
    }
    
    void Component::Draw(graphics::Renderer * renderer) {
      
    }
    
  }
}
