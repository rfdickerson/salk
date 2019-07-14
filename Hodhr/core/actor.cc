//
//  actor.cpp
//  Hodhr
//
//  Created by Robert F. Dickerson on 5/24/19.
//  Copyright © 2019 Robert F. Dickerson. All rights reserved.
//

#include "actor.h"

#include <glm/gtc/matrix_transform.hpp>

namespace hodhr {
namespace core {

Actor::Actor():
direction_(glm::vec3(0, 0, 1)),
up_(glm::vec3(0, 1, 0)),
horizontal_angle_(0.0),
vertical_angle_(0.0)
{}

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

std::string Actor::Name() const {
  return name_;
}

glm::vec3 Actor::Position() const {
  return position_;
}

void Actor::SetPosition(glm::vec3 position) {
  position_ = position;
}

glm::vec3 Actor::Direction() const {
  return direction_;
}

glm::vec3 Actor::Up() const {
  return up_;
}
  
glm::vec3 Actor::Right() const {
  return right_;
}

std::vector<Component*> Actor::Components() const {
  return components_;
}

glm::mat4 Actor::ModelMatrix() const {
  return glm::translate(glm::mat4(1.0), position_);
}

void Actor::SetHorizontalAngle(float angle) {
    horizontal_angle_ = angle;
    UpdateDirections();
}

void Actor::SetVerticalAngle(float angle) {
    vertical_angle_ = angle;
    UpdateDirections();
}

void Actor::UpdateDirections() {
  direction_ = glm::vec3(
                          glm::cos(vertical_angle_) * glm::sin(horizontal_angle_),
                          glm::sin(vertical_angle_),
                          glm::cos(vertical_angle_) * glm::cos(horizontal_angle_)
                          );
  
  right_ = glm::vec3(
                      glm::sin(horizontal_angle_ - glm::pi<float>() / 2.0f),
                      0,
                      glm::cos(horizontal_angle_ - glm::pi<float>() / 2.0f)
                      );
  
  up_ = glm::cross(right_, direction_);
}

}
}
