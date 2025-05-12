#ifndef NODE
#define NODE

#include <vector>

#include "Entity.h"
#include "utils/Utils.h"


namespace ui
{  
  class Node : public Entity
  {
  protected:
    ui::Entity* m_parent;
    std::vector<ui::Entity*> m_childer;
  public:
    bool addChild(ui::Entity* child);
    bool initialize(std::string id, ui::Entity* parent);
    bool dispose();

  };

  
} // namespace ui

#endif