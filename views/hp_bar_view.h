#pragma once

#include "views/view.h"

class HpBar;
class Player;

class HpBarView : public View {
private:
    const HpBar* hp_bar_;
    const Player* player_;
public:
    HpBarView(const HpBar* hp_bar, const Player* player);
    void Draw(Painter* painter) override;
};
