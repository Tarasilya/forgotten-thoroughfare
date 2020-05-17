#include "mouse.h"


namespace component {

bool Mouse::IsLeftPressed() {
    return left_pressed_;
}
void Mouse::SetLeftPressed(bool value) {
    left_pressed_ = value;
}

}
