#include "window.h"

#include <iostream>

namespace hodhr {
namespace graphics {
    
Window::Window()
: width_(1280),
  height_(720),
  fullscreen_(false)
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
  

  
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  
  SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
  SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
  SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3 );
  
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                      SDL_GL_CONTEXT_PROFILE_CORE);
  
  SDL_GL_SetSwapInterval(1);
  
  sdl_main_context_ = SDL_GL_CreateContext(sdl_main_window_);
  if (sdl_main_context_ == nullptr) {
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
