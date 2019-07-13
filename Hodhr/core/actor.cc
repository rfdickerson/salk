//
//  actor.cpp
//  Hodhr
//
//  Created by Robert F. Dickerson on 5/24/19.
//  Copyright © 2019 Robert F. Dickerson. All rights reserved.
//

#include "actor.h"

#include <glm/gtx/transform.hpp>

namespace hodhr {
namespace core {

Actor::Actor() {}

Actor::~Actor() {}

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


  
glm::vec3 Actor::Position() const {
  return position_;
}

void Actor::SetPosition(glm::vec3 position) {
  position_ = position;
}

std::vector<Component*> Actor::Components() const {
  return components_;
}

glm::mat4 Actor::ModelMatrix() const {
  return glm::translate(glm::mat4(), position_);
}

}
}
