#include "widgets/Node.h"

using namespace ui;

Node::Node(/* args */){}
Node::~Node(){}

bool Node::initialize(std::string id, ui::Entity* parent)
{
  m_parent = parent;
  return Entity::initialize(id);
}

bool Node::addChild(ui::Entity* child)
{
  m_childer.push_back(child);
}

bool Node::dispose()
{
  while (!m_childer.empty())
  {
    m_childer.back()->dispose();
    m_childer.pop_back();
  }
  
  return Entity::dispose();
}