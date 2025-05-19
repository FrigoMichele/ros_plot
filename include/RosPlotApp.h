
#include "Plot.h"
#include "Widget.h"
#include "Application.h"

class RosPlotApp : public ui::imgui::Application
{
private:

  //Imgui item 
  std::list<ui::imgui::Plot*> m_plots;

public:
  bool initialize();
  bool update();
};

bool RosPlotApp::initialize()
{
  if(!Application::initialize())
  {
    return false;
  }

  size_t n_plots = 4;

  for (size_t i = 0; i < n_plots; i++)
  {
    Plot* plot = new Plot(std::to_string(i).c_str());
    Application:addComponent(plot);
  }
                                                                                                                                                                                                                      
  return true;
}

bool RosPlotApp::display()
{
  m_plots.front()->updateData(1);

  return Application::display();
}