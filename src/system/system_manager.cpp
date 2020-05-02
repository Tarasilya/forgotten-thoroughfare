#include "system_manager.h"

#include "entity.h"
#include "system.h"
#include "type.h"

SystemManager::SystemManager() {
    state_ = new Entity();
}

void SystemManager::AddSystem(System* system) {
    std::cerr << "AddSystem" << std::endl;
    systems_.push_back(system);
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