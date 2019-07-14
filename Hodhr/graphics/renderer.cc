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
  
  window_.Init();
  
  GLenum result = glewInit();
  
  if (result != GLEW_OK) {
    std::cerr << "Problem initializing GLEW" << std::endl;
    exit(1);
  } else {
    int value = 0;
    SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &value);
    std::cout << "Major version " << value << std::endl;
    
    SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &value);
    std::cout << "Minor version " << value << std::endl;
  }
  
  glClearColor(0.0f, 0.5f, 1.0f, 0.0f);
  
  // initialize the shaders
  physical_shader = Shader::BuildShader("resources/shaders/physical.vert.glsl", 
                                        "resources/shaders/physical.frag.glsl");
  
}

void Renderer::Draw(const core::Scene &scene) {
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  for (auto actors: scene.Actors()) {
    for (auto component: actors.Components()) {
      component->Draw(this);
    }
  }
  
  window_.Swap();
}

core::Scene * Renderer::CurrentScene() const {
  return current_scene_;
}

void Renderer::SetCurrentScene(core::Scene * scene) {
  current_scene_ = scene;
}

Shader * Renderer::PhysicalShader() const {
  return physical_shader;
}
    
}
}
