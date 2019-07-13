#ifndef HODHR_GRAPHICS_WINDOW_H_
#define HODHR_GRAPHICS_WINDOW_H_

#include <SDL2/SDL.h>

namespace hodhr {
namespace graphics {
        
class Window {
            
 public:
  Window();
  ~Window();
            
  void Init();
  void Swap();
            
 private:
  SDL_Window *sdl_main_window_;
  SDL_GLContext sdl_main_context_;
            
  int width_;
  int height_;
  bool fullscreen_;
            
};

}
}

#endif // HODHR_GRAPHICS_WINDOW_H_
