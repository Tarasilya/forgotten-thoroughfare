#pragma once

class GameObject;
class Painter;

class View {
public:
    virtual void Draw(Painter* painter) = 0;
};