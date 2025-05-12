#include "imgui/Widget.h"

using namespace ui::imgui;

bool Widget::render()
{
  return true;
}

bool Widget::openContext()
{
  ImGui::Begin(ui::Widget::m_id.c_str());
  return true;
}

bool Widget::closeContex()
{
  ImGui::End();
  return true;
}