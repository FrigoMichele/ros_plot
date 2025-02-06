#ifndef PLOT_H
#define PLOT_H

#include "Window.h"
#include "implot.h" 

class Plot : public Window
{
private:
  /* data */
public:
  Plot();
~Plot();

  bool openContext() override;
  bool render() override;
  bool closeContex() override;
};

#endif