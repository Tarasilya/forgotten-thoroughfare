#pragma once

#include "views/view.h"

class Attack;

class AttackView : public View {
private:
    const Attack* attack_;
public:
    AttackView(const Attack* attack);
    void Draw(Painter* painter) override;
};
