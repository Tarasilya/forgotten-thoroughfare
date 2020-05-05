#include "system_manager.h"

#include "entity.h"
#include "system.h"
#include "type.h"

namespace systems {

SystemManager::SystemManager() {
    state_ = new Entity("globalState");
}

void SystemManager::AddSystem(System* system) {
    std::cerr << "added (" << system->Name() << ")" << std::endl;
    systems_.push_back(system);
    system->PrintComponents();
}
void SystemManager::AddEntity(Entity* entity) {
    for (auto system: systems_) {
        system->TryAddEntity(entity);
    }
}

void SystemManager::RemoveEntity(Entity* entity) {
    for (auto system: systems_) {
        system->RemoveEntity(entity);
    }
}

void SystemManager::Tick(double dt) {
    for (auto system: systems_) {
        system->Tick(dt);
    }
}

}
