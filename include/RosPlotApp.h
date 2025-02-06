#include "Application.h"

#include "Plot.h"
#include "Window.h"

class RosPlotApp : public Application
{
private:
  //Imgui item 
  std::list<std::unique_ptr<Plot>> m_plots;

public:
  RosPlotApp(/* args */);
  ~RosPlotApp();

  bool initialize();
};

RosPlotApp::RosPlotApp(/* args */)
{
}

RosPlotApp::~RosPlotApp()
{
}

bool RosPlotApp::initialize()
{
  if(!Application::initialize())
  {
    return false;
  }


  m_plots.push_back(std::unique_ptr<Plot>());
  m_plots.push_back(std::unique_ptr<Plot>());
  m_plots.push_back(std::unique_ptr<Plot>());

  for (auto it = m_plots.begin(); it != m_plots.end(); ++it)
  {
    Application::addComponent(std::move(*it));
  }

  return true;
}