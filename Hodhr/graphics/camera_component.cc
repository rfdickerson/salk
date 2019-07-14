#include "camera_component.h"
#include "../core/actor.h"

#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//#define GLM_FORCE_RADIANS

namespace hodhr {
namespace graphics {
    
CameraComponent::CameraComponent()
:
near_(0.1f),
far_(100.0f),
direction_(glm::vec3(0, 0, 1)),
up_(glm::vec3(0, 1, 0)),
field_of_view_(45.0f),
aspect_ratio_(1.0),
horizontal_angle_(0.0),
vertical_angle_(0.0)
{
  
}

CameraComponent::~CameraComponent() {
  
}

void CameraComponent::Init() {
  
  projection_matrix_ = glm::perspective(
                                        glm::radians(field_of_view_),
                                        aspect_ratio_,
                                        near_,
                                        far_
                                        );
  
  Update(0);
  
}

void CameraComponent::Update(float dt) {
  
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
  
  view_matrix_ = glm::lookAt(
                              parent_->Position(),
                              parent_->Position() + direction_,
                              up_
                              );
  
  
  
}

glm::mat4 CameraComponent::ViewMatrix() const {
  return view_matrix_;
}

glm::mat4 CameraComponent::ProjectionMatrix() const {
  return projection_matrix_;
}

}
}
