#ifndef WIDGET_H
#define WIDGET_H
#include <string>
#include <list>
#include <memory>

#include "imgui.h"
#include "IRenderable.h"

class Widget : public IRenderable
{
protected:
  std::string m_name;
public:
  Widget();
  Widget(std::string name);
  ~Widget();

  bool openContext() override;
  bool render() override;
  bool closeContex() override;
};

Widget::Widget() : Widget("windows")
{

}

Widget::Widget(std::string name) : m_name(name)
{
}

Widget::~Widget()
{
}

bool Widget::openContext()
{
  ImGui::Begin(m_name.c_str());
}

bool Widget::render()
{

}

bool Widget::closeContex()
{
  ImGui::End();
}

#endif