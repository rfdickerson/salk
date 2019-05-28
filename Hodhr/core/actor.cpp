//
//  actor.cpp
//  Hodhr
//
//  Created by Robert F. Dickerson on 5/24/19.
//  Copyright © 2019 Robert F. Dickerson. All rights reserved.
//

#include "actor.hpp"


namespace hodhr {
namespace core {

  void Actor::Init() {
    for (auto component : components_) {
      component->Init();
    }
  }
  
  void Actor::Attach(Component * component) {
    components_.push_back(component);
    component->Attach(this);
  }
  
void Actor::Update(float dt) {
  for (auto component : components_) {
    component->Update(dt);
  }
}

  Actor::Actor() {}
  
  Actor::~Actor() {
    
  }
  
  glm::vec3 Actor::Position() const {
    return position_;
  }
  
  std::vector<Component*> Actor::Components() const {
    return components_;
  }
  
}
}
