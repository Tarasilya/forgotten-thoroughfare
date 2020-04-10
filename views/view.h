#pragma once

class GameObject;
class Painter;

class View {
private:
    int z_;
public:
    View();
    int Z();
    void SetZ(int z);
    virtual void Draw(Painter* painter) = 0;
};