#pragma once

#include "views/view.h"

class HpBar;
class GameObject;

class HpBarView : public View {
private:
    const HpBar* hp_bar_;
    const GameObject* object_;
public:
    HpBarView(const HpBar* hp_bar, const GameObject* object);
    void Draw(Painter* painter) override;
};
