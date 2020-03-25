#pragma once

class GameObject;
class Painter;

class View {
protected:
    int z_;
public:
    int Z();
    virtual void Draw(Painter* painter) = 0;
};