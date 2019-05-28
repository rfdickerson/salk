//
//  renderer.cpp
//  Hodhr
//
//  Created by Robert F. Dickerson on 5/22/19.
//  Copyright © 2019 Robert F. Dickerson. All rights reserved.
//

#include "renderer.h"

#include <GL/glew.h>

#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

namespace hodhr {
  namespace graphics {
    
    Renderer::Renderer() {
      
    }
    
    Renderer::~Renderer() {
      delete physical_shader;
    }
    
    void Renderer::Init() {
      
      glewExperimental = GL_TRUE;
      
      SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
      SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
      
      SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                          SDL_GL_CONTEXT_PROFILE_CORE);
      
      window_.Init();
      
      GLenum result = glewInit();
      
      if (result != GLEW_OK) {
        std::cerr << "Problem initializing GLEW" << std::endl;
        exit(1);
      }
      
      glClearColor(0.0f, 0.1f, 0.5f, 0.0f);
      
      // initialize the shaders
      physical_shader = Shader::BuildShader("shaders/physical.vert.glsl", "shaders/physical.frag.glsl");
      
    }
    
    void Renderer::Draw(const core::Scene &scene) {
      
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      
      // set the physical shader
      physical_shader->Use();
      
      GLuint mvp_location = physical_shader->UniformLocation("MVPMatrix");
      
      auto mvp_matrix = scene.GetCamera()->ModelViewMatrix();
      
      glUniformMatrix4fv(mvp_location, 1, GL_FALSE, glm::value_ptr(mvp_matrix));
      
      for (auto actors: scene.Actors()) {
        for (auto component: actors.Components()) {
          component->Draw(this);
        }
      }
      
      window_.Swap();
    }
    
    
  }
}
