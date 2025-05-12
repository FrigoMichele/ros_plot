#ifndef APPLICATION_H
#define APPLICATION_H

#include "imgui/Node.h"

namespace ui
{
  namespace imgui
  {
    class Application : public ui::Node
    {
    public:
      bool initialize();
      bool dispaly();
    };
  }
}
bool Application::initialize()
{
  ui::Node::initialize("Application",this);

  // Add widget
  return true;
}

bool Application::display()
{

  //Iterate over the tree 
  for (auto item : ui::Node::m_children)
    item->openContext();

  for (auto item : ui::Node::m_children)
    item->render();

  for (auto item : ui::Node::m_children)
    item->closeContex();

  return true;
}

#endif