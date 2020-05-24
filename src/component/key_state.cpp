#include "key_state.h"

void KeyState::Update(bool value) {
    previous = current;
    current = value;
}