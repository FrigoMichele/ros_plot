#ifndef PLOT_H
#define PLOT_H

#include <list>
#include <ctime>

#include "implot.h" 
#include "CircularBuffer.h"
#include "Widget.h"

template<class T>
class TimeStampedArray
{
private:
  Circular_Buffer<time_t> m_time;
  Circular_Buffer<T> m_data;
public:
  TimeStampedArray(/* args */);
  ~TimeStampedArray();
  ImPlotPoint getDataPoint(int idx, void* data);

  time_t getTime(int idx);
  T getValue(int idx);
};
template<class T>
TimeStampedArray::TimeStampedArray(/* args */)
{
}
template<class T>
TimeStampedArray::~TimeStampedArray()
{
}
template<class T>
ImPlotPoint 
TimeStampedArray::getDataPoint(int idx, void* data)
{
  TimeStampedArray* my_data = (TimeStampedArray*)data;
  ImPlotPoint p;
  p.x = my_data->getTime(idx);
  p.y = my_data->getValue(idx);
  return p

}

class Plot : public Widget
{
private:
  TimeStampedArray<double> m_data;

public:
  Plot(std::string name);
  ~Plot();

  bool openContext() override;
  bool render() override;
  bool closeContex() override;
};

Plot::Plot(std::string name = "plot") : Widget(name)
{
}

Plot::~Plot()
{
}

bool Plot::openContext()
{
  if(!Widget::openContext())
    return false;

  ImPlot::BeginPlot(m_name.c_str());
}

bool Plot::render()
{
  ImPlot::PlotLineG("line", m_data., nullptr, 1000);
}

bool Plot::closeContex()
{
  ImPlot::EndPlot();

  return Widget::closeContex();

}

#endif