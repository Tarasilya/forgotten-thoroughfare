#include "hp.h"

#include "component/parent_entity.h"
#include "component/rectangle.h"
#include "component/sprite.h"
#include "component/transform.h"
#include "entity.h"
#include "system/system_manager.h"

#include <cmath>


namespace component {

const double HP_HEIGHT = 0.006;

Hp::Hp(int max, Entity* entity, systems::SystemManager* system_manager_): hp_(max), max_(max) {
    green_rect_ = CreateHpRect("hp-green", sf::Color::Green, entity);
    red_rect_ = CreateHpRect("hp-red", sf::Color::Red, entity);
    system_manager_->AddEntity(green_rect_);
    system_manager_->AddEntity(red_rect_);
    UpdateRects();
}

Entity* Hp::CreateHpRect(std::string name, sf::Color color, Entity* entity) {
    Entity* result = new Entity(name);
    result->AddComponent(new component::Rectangle(0, HP_HEIGHT, color, 5));
    result->AddComponent(new component::Transform(0, -HP_HEIGHT));
    result->AddComponent(new component::ParentEntity(entity));
    return result;
}

void Hp::Change(int delta) {
    hp_ += delta;
    hp_ = std::max(0, hp_);
    hp_ = std::min(max_, hp_);
    UpdateRects();
}

void Hp::UpdateRects() {
    double hp_percent = hp_ * 1.0 / max_;
    double parent_width = green_rect_
        ->GetComponent<component::ParentEntity>()
        ->GetParent()
        ->GetComponent<component::Sprite>()
        ->GetSize().first;
    double green_width = parent_width * hp_percent;
    green_rect_->GetComponent<component::Rectangle>()->SetWidth(green_width);

    double red_width = parent_width - green_width;
    red_rect_->GetComponent<component::Rectangle>()->SetWidth(red_width);
    red_rect_->GetComponent<component::Transform>()->SetX(green_width);
    std::cerr << "g: " << green_width 
        << " r: " << red_width 
        << " h: " << hp_percent << std::endl;
}

int Hp::Get() {
    return hp_;
}

}
