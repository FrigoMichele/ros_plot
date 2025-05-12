#ifndef NODE_IMGUI
#define NODE_IMGUI

#include <vector>
#include "../widgets/Node.h"
#include "../imgui/IRenderable.h"

namespace ui
{
  namespace imgui
  {
    class Node : public ui::Node, ui::imgui::IRenderable
    {
      public:
      bool render() override;
      bool openContext() override;
      bool closeContex() override;

    };
  }
} // namespace ui

#endif 