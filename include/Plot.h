#ifndef PLOT_H
#define PLOT_H

#include <list>
#include <ctime>
#include <functional>
#include <chrono>

#include "implot.h" 
#include "CircularBuffer.h"
#include "Widget.h"

template<class T>
class TimestampedBuffer
{
private:
  Circular_Buffer<T> m_time;
  Circular_Buffer<T> m_data;
  const size_t m_max_size = 1000;
public:

  TimestampedBuffer() : m_time(m_max_size), m_data(m_max_size){};
  ~TimestampedBuffer(){};

  inline T* getDataPtr() {return m_data.get_pointer();}
  inline T* getTimePtr() {return m_time.get_pointer();}


  time_t getTime(int idx);
  T getValue(int idx);
  inline size_t size() {return m_data.size();} 

  void setPoint(T data, time_t time)
  {
    if(m_time.is_full())
      m_time.dequeue();

    if(m_data.is_full())
      m_data.dequeue();

    m_time.enqueue(time);
    m_data.enqueue(data);
  }

  void initialize()
  {
    while (!m_time.is_empty())
      m_time.dequeue();

    while (!m_data.is_empty())
      m_data.dequeue();
      
    for (size_t i = 0; i < m_max_size; i++)
      m_time.enqueue(0);
  
    for (size_t i = 0; i <m_max_size; i++)
      m_data.enqueue(0);
  }
 
};

class Plot : public Widget
{
private:
  TimestampedBuffer<double> m_data;

public:
  Plot(std::string name);
  ~Plot();

  bool initialize();
  void updateData(double data);

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

bool Plot::initialize()
{

  if(!Widget::initialize())
    return false;

  m_data.initialize();

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
  ImPlot::PlotLine("line", m_data.getDataPtr(), m_data.getTimePtr(), m_data.size());
}

bool Plot::closeContex()
{
  ImPlot::EndPlot();

  return Widget::closeContex();
}

void Plot::updateData(double data)
{
  const auto now = std::chrono::system_clock::now();
  const std::time_t t_c = std::chrono::system_clock::to_time_t(now);

  m_data.setPoint(data, t_c);
}

#endif