
#include "Plot.h"

Plot::Plot()
{
}

Plot::~Plot()
{
}

bool Plot::openContext()
{
  if(!Window::openContext())
    return false;

  ImPlot::BeginPlot();
}

bool Plot::render()
{

}

bool Plot::closeContex()
{
  ImPlot:EndPlot();

  return Window::closeContex();

}