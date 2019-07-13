//
//  scene.cpp
//  Hodhr
//
//  Created by Robert F. Dickerson on 5/24/19.
//  Copyright © 2019 Robert F. Dickerson. All rights reserved.
//

#include "scene.hpp"

#include "../graphics/geometry_component.hpp"
#include "../graphics/camera_component.hpp"

namespace hodhr {
  namespace core {
    
    Scene::Scene() {
      
    }
    
    Scene::~Scene() {
      
    }
    
    void Scene::Init() {
      
      Actor cube_actor;
      
      auto geometry_component = new graphics::GeometryComponent();
      cube_actor.Attach(geometry_component);
      actors.push_back(cube_actor);
      
      Actor camera_actor;
      camera_actor.SetPosition(glm::vec3(0, 0, -5));
      
      auto camera_component = new graphics::CameraComponent();
      camera_actor.Attach(camera_component);
      actors.push_back(camera_actor);
      
      current_camera = camera_component;
      
      for (Actor actor: actors) {
        actor.Init();
      }
    }
    
    void Scene::Update(float dt) {
      for (Actor actor: actors) {
        actor.Update(dt);
      }
    }
    
    std::vector<Actor> Scene::Actors() const {
      return actors;
    }
    
    graphics::CameraComponent* Scene::GetCamera() const {
      return current_camera;
    }
    
    void Scene::SetCamera(graphics::CameraComponent * camera) {
      current_camera = camera;
    }
    
  }
}
