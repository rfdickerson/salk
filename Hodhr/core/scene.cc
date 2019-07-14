#include "scene.h"

#include "../graphics/geometry_component.h"
#include "../graphics/camera_component.h"

namespace hodhr {
namespace core {
    
Scene::Scene() { }

Scene::~Scene() { }

void Scene::Init() {
  
  Actor cube_actor;
  
  auto geometry_component = new graphics::GeometryComponent();
  cube_actor.Attach(geometry_component);
  actors_.push_back(cube_actor);
  
  Actor camera_actor;
  camera_actor.SetPosition(glm::vec3(0, 0, -5));
  
  auto camera_component = new graphics::CameraComponent();
  camera_actor.Attach(camera_component);
  actors_.push_back(camera_actor);
  
  current_camera_ = camera_component;
  
  for (Actor actor: actors_) {
    actor.Init();
  }
}

void Scene::Update(float dt) {
  for (Actor actor: actors_) {
    actor.Update(dt);
  }
}

std::vector<Actor> Scene::Actors() const {
  return actors_;
}

graphics::CameraComponent* Scene::GetCamera() const {
  return current_camera_;
}

void Scene::SetCamera(graphics::CameraComponent * camera) {
  current_camera_ = camera;
}
    
}
}
