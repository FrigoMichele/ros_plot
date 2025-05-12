#ifndef WIDGET
#define WIDGET

#include <string>

#include "Node.h"
namespace ui
{
    class Widget : public ui::Node
    {
    private:
      /* data */
    public:
      bool initialize(std::string id, ui::Widget* parent);

      bool setSize();

    };
}
#endif