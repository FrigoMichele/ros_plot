#ifndef PLOT_H
#define PLOT_H

#include <list>
#include <ctime>
#include <functional>
#include <chrono>
#include <math.h>

#include "implot.h" 
#include "Widget.h"

// utility structure for realtime plot
struct TimestampedBuffer {
  int MaxSize;
  int Offset;
  ImVector<ImVec2> Data;
  TimestampedBuffer(int max_size = 2000) {
      MaxSize = max_size;
      Offset  = 0;
      Data.reserve(MaxSize);
  }
  void AddPoint(float x, float y) {
      if (Data.size() < MaxSize)
          Data.push_back(ImVec2(x,y));
      else {
          Data[Offset] = ImVec2(x,y);
          Offset =  (Offset + 1) % MaxSize;
      }
  }
  void Erase() {
      if (Data.size() > 0) {
          Data.shrink(0);
          Offset  = 0;
      }
  }

  ImVec2 getFront()
  {
    if (Data.size() < MaxSize)
      return Data.front();
    else
      return Data[Offset];
  }

  ImVec2 getBack()
  {
    if (Data.size() < MaxSize)
    return Data.back();
  else
    return Data[((Offset + 1) % MaxSize)];
  }

};

class Plot : public Widget
{
private:
  TimestampedBuffer m_data;
  float m_time;

public:
  Plot(std::string name = "plot");
  ~Plot();

  bool initialize();
  void updateData(double data);

  bool openContext() override;
  bool render() override;
  bool closeContex() override;
};

Plot::Plot(std::string name) : Widget(name)
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
}

bool Plot::render()
{
  if(!m_data.Data.empty())
  {
    //ImPlot::SetupAxesLimits(m_data.getBack().x, m_data.getFront().x, m_data.getBack().y, m_data.getFront().y,ImPlotCond_Always);
    ImPlot::PlotLine("line", &m_data.Data[0].x, &m_data.Data[0].y, m_data.Data.size(), 0, m_data.Offset, 2*sizeof(float));
  }
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

#endif