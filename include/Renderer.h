#ifndef APPLICATION_H
#define APPLICATION_H

#include <list>
#include <memory>
#include "IRenderable.h"


class Renderer
{
private:
 std::list<IRenderable*> m_items;

public:
  Renderer(/* args */);
  ~Renderer();
  bool initialize();
  bool addComponent(IRenderable* item);
  bool update();
};

Renderer::Renderer(/* args */)
{
}

Renderer::~Renderer()
{
}

bool Renderer::initialize(){ return true; }

bool Renderer::addComponent(IRenderable* item)
{
  m_items.push_back(item);
}

bool Renderer::update()
{
  for (auto it = m_items.begin(); it != m_items.end(); ++it)
  {
    (*it)->openContext();

    (*it)->render();

    (*it)->closeContex();
  }
}

#endif