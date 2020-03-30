#pragma once

class Player;

class HpBar {
private:
    double current_;
    double max_;
public:
    HpBar(double max, const Player* player);
    double GetCurrent() const;
    double GetMax() const;
    void Change(double delta);
};
