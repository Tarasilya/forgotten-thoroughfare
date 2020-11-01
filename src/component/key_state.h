#pragma once

struct KeyState {
    bool previous = false;
    bool current = false;

    void Update(bool value);
};