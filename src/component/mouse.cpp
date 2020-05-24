#include "mouse.h"


namespace component {

KeyState Mouse::LeftState() {
    return left_;
}
void Mouse::UpdateLeft(bool value) {
    left_.Update(value);
}

}
