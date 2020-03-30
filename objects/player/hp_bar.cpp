#include "hp_bar.h"

#include "painter/painter.h"
#include "views/hp_bar_view.h"

HpBar::HpBar(double max, const Player* player): max_(max), current_(max) {
    Painter::GetPainter()->AddView(new HpBarView(this, player));
}

double HpBar::GetCurrent() const {
    return current_;
}

double HpBar::GetMax() const {
    return max_;
}

void HpBar::Change(double delta) {
    current_ += delta;
    if (current_ < 0) {
        current_ = 0;
    }
    if (current_ > max_) {
        current_ = max_;
    }
}
