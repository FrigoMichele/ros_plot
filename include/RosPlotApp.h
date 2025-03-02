#include "Renderer.h"

#include "Plot.h"
#include "Widget.h"
#include "ItemList.h"

class RosPlotApp : public Renderer
{
private:
  //Imgui item 
  std::list<Plot*> m_plots;
  ItemList* m_list;

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

  m_list = new ItemList();
  m_list->initialize();
  Renderer::addComponent(m_list);

  return true;
}


bool RosPlotApp::update()
{
  m_plots.front()->updateData(1);


  return Renderer::update();
}