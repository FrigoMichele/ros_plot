#include "include/widgets/Entity.h"

using namespace ui;

Entity::Entity(/* args */) : m_id(""){}
Entity::~Entity(){}

bool Entity::initialize(std::string id)
{
  m_id = id;
  return true;
}
