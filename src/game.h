#pragma once 

namespace systems {
class SystemManager;
}

class Game {
private:
    systems::SystemManager* system_manager_;

    void InitState();
    void InitSystems();

    void InitRat();
    void InitPunchingBags();
public:
    Game();

    void Run();
};