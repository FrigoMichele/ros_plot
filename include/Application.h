#ifndef APPLICATION_H
#define APPLICATION_H

#include <list>
#include <memory>
#include "IRenderable.h"


class Application
{
private:
 std::list<std::unique_ptr<IRenderable>> m_items;

public:
  Application(/* args */);
  ~Application();
  bool initialize();
  bool addComponent(std::unique_ptr<IRenderable> item);
  bool update();
};

Application::Application(/* args */)
{
}

Application::~Application()
{
}

bool Application::initialize(){ return true; }

bool Application::addComponent(std::unique_ptr<IRenderable> item)
{
  m_items.push_back(std::move(item));
}

bool Application::update()
{
  for (auto it = m_items.begin(); it != m_items.end(); ++it)
    (*it)->openContext();
  
  for (auto it = m_items.begin(); it != m_items.end(); ++it)
    (*it)->render();

  for (auto it = m_items.begin(); it != m_items.end(); ++it)
    (*it)->closeContex();
}

#endif