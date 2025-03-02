
#include <string>
#include <vector>
#include <map>

#include "Widget.h"

class RosMsgViewer
{
private:
  std::vector<std::string> m_msg;

public:
  RosMsgViewer(/* args */);
  ~RosMsgViewer();
};

RosMsgViewer::RosMsgViewer(/* args */)
{
}

RosMsgViewer::~RosMsgViewer()
{
}


class ItemList : public Widget
{
private:
std::map<std::string, std::vector<std::string>> m_topics;
unsigned int current_part_idx;

public:
  ItemList(/* args */);
  ~ItemList();
  void initilaize();

  bool openContext() override;
  bool render() override;
  bool closeContex() override;

};

ItemList::ItemList(/* args */)
{
}

ItemList::~ItemList()
{
}

void ItemList::initilaize()
{
  //m_topics =  get_topic_names_and_types();
  std::vector<std::string> v = {"8", "4", "5", "9"};
  for (int n = 0; n < 50; n++)
    m_topics.insert({std::to_string(n), v});
    
  current_part_idx = 0;
}

bool ItemList::openContext()
{
  if(!Widget::openContext())
    return false;

  ImGui::BeginChild("Scrolling");
}

bool ItemList::render()
{
  const char* items[] = { "AAAA", "BBBB", "CCCC", "DDDD", "EEEE", "FFFF", "GGGG", "HHHH", "IIII", "JJJJ", "KKKK", "LLLLLLL", "MMMM", "OOOOOOO" };
  static int item_selected_idx = 0; // Here we store our selected data as an index.

  static bool item_highlight = false;
  int item_highlighted_idx = -1; // Here we store our highlighted data as an index.
  ImGui::Checkbox("Highlight hovered item in second listbox", &item_highlight);

  if (ImGui::BeginListBox("listbox 1"))
  {
      for (int n = 0; n < IM_ARRAYSIZE(items); n++)
      {
          const bool is_selected = (item_selected_idx == n);
          if (ImGui::Selectable(items[n], is_selected))
              item_selected_idx = n;

          if (item_highlight && ImGui::IsItemHovered())
              item_highlighted_idx = n;

          // Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
          if (is_selected)
              ImGui::SetItemDefaultFocus();
      }
      ImGui::EndListBox();
  }
}

bool ItemList::closeContex()
{
  ImGui::EndChild();

  return Widget::closeContex();
}
