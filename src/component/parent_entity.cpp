#include "parent_entity.h"


namespace component {

ParentEntity::ParentEntity(Entity* parent): parent_(parent) {}

Entity* ParentEntity::GetParent() {
    return parent_;
}

}
