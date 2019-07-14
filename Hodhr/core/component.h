#ifndef component_hpp
#define component_hpp

//#include "../graphics/renderer.h"

namespace hodhr {
  
  namespace graphics {
    class Renderer;
  }
  
namespace core {

// forward define for Actor since cyclical
class Actor;
  
class Component {
public:
  Component();
  virtual ~Component();
  
  virtual void Init() = 0;
  virtual void Update(float dt);
  virtual void Draw(graphics::Renderer * renderer);
  
  void Attach(Actor *actor);
  
protected:
  Actor * parent_;
  
};
  
}
}

#endif /* component_hpp */
