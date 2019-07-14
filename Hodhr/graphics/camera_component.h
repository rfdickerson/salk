#ifndef camera_component_hpp
#define camera_component_hpp

#include "../core/component.h"

#include <stdio.h>

#include <GL/glew.h>
#include <glm/glm.hpp>

namespace hodhr {
namespace graphics {
  
class CameraComponent: public core::Component {
public:
  CameraComponent();
  ~CameraComponent();

  void Init();
  virtual void Update(float dt);

  glm::mat4 ViewMatrix() const;
  glm::mat4 ProjectionMatrix() const;
  
private:
  
  // near plane
  GLfloat near_;

  // far plane
  GLfloat far_;

  GLfloat field_of_view_;
  GLfloat aspect_ratio_;

  glm::mat4 projection_matrix_;
  glm::mat4 view_matrix_;


  
};

}
}

#endif /* camera_component_hpp */
