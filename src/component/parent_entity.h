#pragma once

#include "component.h"


class Entity;

namespace component {

class ParentEntity: public Component {
private:
    Entity* parent_;
public:
    ParentEntity(Entity* parent);

    Entity* GetParent();
};

}
