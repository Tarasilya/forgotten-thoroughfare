#pragma once 

namespace systems {
class SystemManager;
}

class Game {
private:
    systems::SystemManager* system_manager_;

    void InitState();
    void InitSystems();

public:
    Game();

    void Run();
};