
#include "widgets/Widget.h"

using namespace ui;

bool Widget::initialize(std::string id, ui::Widget* parent)
{

  // [FUTURE] Redoundant to with method of node 
  if(!Node::initialize(id, parent))
    return false;

  return true;
}

bool Widget::setSize()
{
  return true;
} 