//
//  engine.cpp
//  Hodhr
//
//  Created by Robert F. Dickerson on 5/22/19.
//  Copyright © 2019 Robert F. Dickerson. All rights reserved.
//

#include "engine.h"

#include <iostream>

#include <SDL2/SDL.h>


namespace hodhr {
  namespace core {
    
    Engine::Engine(): done_(false) {
      
    }
    
    Engine::~Engine() {
      SDL_Quit();
    }
    
    void Engine::Start() {
      if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER)) {
        std::cerr << "Could not initialize SDL" << std::endl;
        exit(1);
      } else {
        std::cout << "Initialized SDL" << std::endl;
      }
      
      renderer_.Init();
      
      scene_.Init();
      
      renderer_.SetCurrentScene(&scene_);
      
      Run();
      
    }
    
    void Engine::Run() {
      float dt = 0;
      while (done_ == 0) {
        Uint64 t0 = SDL_GetPerformanceCounter();
        Uint64 freq = SDL_GetPerformanceFrequency();
        
        renderer_.Draw(scene_);
        scene_.Update(dt);
        
        Uint64 now = SDL_GetPerformanceCounter();
        dt = static_cast<float>(now - t0) / static_cast<float>(freq * 1000);
        
        HandleUserInput(dt);
      }
    }
    
    void Engine::HandleUserInput(float dt) {
      SDL_Event event;
      
      while (SDL_PollEvent(&event)) {
        
        if (event.type == SDL_QUIT) { done_ = true; }
        if (event.type == SDL_KEYDOWN) { done_ = true; }
      }
    }
    
  }
}
