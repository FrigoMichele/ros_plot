#ifndef WIDGET_IMGUI
#define WIDGET_IMGUI

#include"imgui.h"

#include"../widgets/Widget.h"
#include"../imgui/Node.h"

namespace ui
{
  namespace imgui
  {
    class Widget :  public virtual ui::Widget,  public virtual ui::imgui::Node
    {
    public:
      bool render();
      bool openContext();
      bool closeContex();
    };
  }
}

#endif