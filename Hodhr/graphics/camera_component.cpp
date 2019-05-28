//
//  camera_component.cpp
//  Hodhr
//
//  Created by Robert F. Dickerson on 5/27/19.
//  Copyright © 2019 Robert F. Dickerson. All rights reserved.
//

#include "camera_component.hpp"
#include "../core/actor.hpp"

#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>


namespace hodhr {
  namespace graphics {
    
    CameraComponent::CameraComponent()
    :
    near_(0.1f),
    far_(100.0f),
    direction_(glm::vec3(0, 0, 1)),
    field_of_view_(90.0f),
    aspect_ratio_(1.0)
    {
      
    }
    
    CameraComponent::~CameraComponent() {
      
    }
    
    void CameraComponent::Init() {
      
      projection_matrix_ = glm::perspective(
                                            field_of_view_,
                                            aspect_ratio_,
                                            near_,
                                            far_
                                            );
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
    
    glm::mat4 CameraComponent::ModelViewMatrix() const {
      return view_matrix_ * projection_matrix_;
    }
    
  }
}
