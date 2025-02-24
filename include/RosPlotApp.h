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
  bool update();
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

  size_t n_plots = 4;

  for (size_t i = 0; i < n_plots; i++)
  {
    Plot* plot = new Plot(std::to_string(i).c_str());
    plot->initialize();
    m_plots.push_back(plot);
  }
  
  for (auto it = m_plots.begin(); it != m_plots.end(); ++it)
  {
    Renderer::addComponent((*it));
  }

  return true;
}


bool RosPlotApp::update()
{
  m_plots.front()->updateData(rand());


  return Renderer::update();
}