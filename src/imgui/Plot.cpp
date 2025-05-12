
#include "include/imgui/Plot.h"

using namespace ui::imgui

Plot::Plot(std::string name) : Widget(name)
{
  
}

Plot::Plot() : Widget(" ")
{
  
}

Plot::~Plot()
{
}

bool Plot::initialize()
{

  if(!Widget::initialize())
    return false;

  m_time = 0;

  return true;
}

bool Plot::openContext()
{
  if(!Widget::openContext())
    return false;

  ImPlot::BeginPlot(m_name.c_str());

  return true;
}

bool Plot::render()
{
  if(!m_data.Data.empty())
  {
    //ImPlot::SetupAxesLimits(m_data.getBack().x, m_data.getFront().x, m_data.getBack().y, m_data.getFront().y,ImPlotCond_Always);
    ImPlot::PushStyleVar(ImPlotStyleVar_LineWeight, 5);
    ImPlot::PlotLine("line", &m_data.Data[0].x, &m_data.Data[0].y, m_data.Data.size(), 0, m_data.Offset, 2*sizeof(float));
    ImPlot::PopStyleVar();
  }

  return true;
}

bool Plot::closeContex()
{
 
  ImPlot::EndPlot();

  return Widget::closeContex();
}

void Plot::updateData(double data)
{
  m_time += ImGui::GetIO().DeltaTime;
  m_data.AddPoint(sin(m_time), m_time);
}