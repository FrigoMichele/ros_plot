#ifndef PLOT_H
#define PLOT_H

#include "Window.h"
#include "implot.h" 

class Plot : public Window
{
private:
  /* data */
public:
  Plot(std::string name);
  ~Plot();

  bool openContext() override;
  bool render() override;
  bool closeContex() override;
};

Plot::Plot(std::string name = "plot") : Window(name)
{
}

Plot::~Plot()
{
}

bool Plot::openContext()
{
  if(!Window::openContext())
    return false;

  ImPlot::BeginPlot(m_name.c_str());
}

bool Plot::render()
{

}

bool Plot::closeContex()
{
  ImPlot::EndPlot();

  return Window::closeContex();

}

#endif