#ifndef engine_hpp
#define engine_hpp

#include "../graphics/renderer.h"
#include "scene.h"

namespace hodhr {
namespace core {
        
class Engine {
 public:
  Engine();
  ~Engine();
    
  void Start();
    
 private:
  void Run();
  void HandleUserInput(float dt);
    
  graphics::Renderer renderer_;
  Scene scene_;
  
  bool done_;
  
    
};
        
} // namespace core
} // namespace hodhr

#endif /* engine_hpp */
