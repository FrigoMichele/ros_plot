#ifndef I_RENDERABLE_H
#define I_RENDERABLE_H
namespace ui
{  
  namespace imgui
  {
    class IRenderable
    {
      public:
        virtual bool render() = 0;
        virtual bool openContext() = 0;
        virtual bool closeContex() = 0;
    };
  }
}

#endif