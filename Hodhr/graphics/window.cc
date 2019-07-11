//
//  window.cpp
//  Hodhr
//
//  Created by Robert F. Dickerson on 5/21/19.
//  Copyright © 2019 Robert F. Dickerson. All rights reserved.
//

#include "window.h"

#include <iostream>

namespace hodhr {
  namespace graphics {
    
    Window::Window()
    : fullscreen_(false),
    width_(512),
    height_(512)
    {
      
      
      
    }
    
    Window::~Window() {
      SDL_GL_DeleteContext(sdl_main_context_);
      SDL_DestroyWindow(sdl_main_window_);
    }
    
    void Window::Init() {
      Uint32 flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;
      
      sdl_main_window_ = SDL_CreateWindow("Hodhr",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          width_,
                                          height_,
                                          flags);
      
      
      
      sdl_main_context_ = SDL_GL_CreateContext(sdl_main_window_);
      if (sdl_main_context_ == NULL) {
        std::cout << "OpenGL context could not be created!" << std::endl;
        exit(1);
      }
      
      SDL_GL_MakeCurrent(sdl_main_window_, sdl_main_context_);
      
      SDL_GL_SetSwapInterval(1);
    }
    
    void Window::Swap() {
      SDL_GL_SwapWindow(sdl_main_window_);
    }
  }
}
