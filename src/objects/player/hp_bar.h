#pragma once

class GameObject;

class HpBar {
private:
    double current_;
    double max_;
public:
    HpBar(double max, const GameObject* player);
    double GetCurrent() const;
    double GetMax() const;
    void Change(double delta);
};
