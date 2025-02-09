#include "Renderer.h"

#include "Plot.h"
#include "Widget.h"

class RosPlotApp : public Renderer
{
private:
  //Imgui item 
  std::list<Plot*> m_plots;

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
  for (auto it = m_plots.begin(); it != m_plots.end(); ++it)
    delete *it;

}

bool RosPlotApp::initialize()
{
  if(!Renderer::initialize())
  {
    return false;
  }

  m_plots.push_back(new Plot("1"));
  m_plots.push_back(new Plot("2"));
  m_plots.push_back(new Plot("3"));

  for (auto it = m_plots.begin(); it != m_plots.end(); ++it)
  {
    Renderer::addComponent((*it));
  }

  return true;
}