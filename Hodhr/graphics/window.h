//
//  window.hpp
//  Hodhr
//
//  Created by Robert F. Dickerson on 5/21/19.
//  Copyright © 2019 Robert F. Dickerson. All rights reserved.
//

#ifndef window_hpp
#define window_hpp

#include <stdio.h>
#include <string>

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

#endif /* window_hpp */
