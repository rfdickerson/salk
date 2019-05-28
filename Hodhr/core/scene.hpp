//
//  scene.hpp
//  Hodhr
//
//  Created by Robert F. Dickerson on 5/24/19.
//  Copyright © 2019 Robert F. Dickerson. All rights reserved.
//

#ifndef scene_hpp
#define scene_hpp

#include <stdio.h>
#include <vector>

#include "actor.hpp"
#include "../graphics/camera_component.hpp"

namespace hodhr {
  namespace core {

    class Scene {
    public:
      Scene();
      ~Scene();
      
      void Init();
      void Update(float dt);
      
      std::vector<Actor> Actors() const;
      
      graphics::CameraComponent* GetCamera() const;
      void SetCamera(graphics::CameraComponent * camera);
      
    private:
      
      std::vector<Actor> actors;
      
      graphics::CameraComponent * current_camera;
    };
    
  }
}

#endif /* scene_hpp */
