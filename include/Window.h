#ifndef WINDOWS_H
#define WINDOWS_H
#include <string>
#include <list>
#include <memory>

#include "imgui.h"
#include "IRenderable.h"

class Window : public IRenderable
{
protected:
  std::string m_name;
public:
  Window();
  Window(std::string name);
  ~Window();

  bool openContext() override;
  bool render() override;
  bool closeContex() override;
};

Window::Window() : Window("windows")
{

}

Window::Window(std::string name) : m_name(name)
{
}

Window::~Window()
{
}

bool Window::openContext()
{
  ImGui::Begin(m_name.c_str());
}

bool Window::render()
{

}

bool Window::closeContex()
{
  ImGui::End();
}

#endif