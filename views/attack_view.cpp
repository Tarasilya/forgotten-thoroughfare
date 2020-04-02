#include "attack_view.h"

#include "objects/player/attack.h"
#include "painter/painter.h"


const Color STARTUP_COLOR = Color(100, 100, 100);
const Color ACTIVE_COLOR = Color(0, 0, 0);


AttackView::AttackView(const Attack* attack): attack_(attack) {
    z_ = 100;
}

void AttackView::Draw(Painter* painter) {
    State state = attack_->GetState();
    RectCollisionBox* box = (RectCollisionBox*) attack_->GetCollisionBox();
    Color color;
    switch(state) {
        case STARTUP:
            color = STARTUP_COLOR;
            break;
        case ACTIVE:
            color = ACTIVE_COLOR;
            break;
        default:
            return;
    }
    painter->Draw({box->x1, box->y1, box->x2, box->y2, color});
}
