#ifndef PLOT_H
#define PLOT_H

#include <list>
#include <ctime>
#include <functional>
#include <chrono>
#include <math.h>

#include "implot.h" 

#include "../widgets/Widget.h"
#include "../utils/Buffer.h"

namespace ui::imgui
{
  class Plot : public ui::Widget
  {
    private:
      TimestampedBuffer m_data;
      float m_time;

    public:
      Plot(std::string name = "plot");
      Plot();
      ~Plot();

      bool initialize();
      void updateData(double data);

      bool openContext() override;
      bool render() override;
      bool closeContex() override;
  };
}

#endif