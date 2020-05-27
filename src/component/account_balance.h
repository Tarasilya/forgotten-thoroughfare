#pragma once

#include "component.h"

#include <string>

class Entity;

namespace component {

class AccountBalance: public Component {
private:
    int money_; 
public:
    AccountBalance();
    AccountBalance(int money);
    int Get();
    static void ChangeText(Entity* entity);
    static bool ChangeMoney(Entity* entity, int delta_money);
};

}
