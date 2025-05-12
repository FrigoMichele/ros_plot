#ifndef ENTITY
#define ENTITY

#include  <string>

#include "IDisposable.h"

namespace ui
{
class Entity : public IDisposable
  {
  protected:
    std::string m_id;
  public:
    bool initialize(std::string id);
  };
} // namespace ui

#endif
