#include "system_manager.h"

#include "entity.h"
#include "system.h"
#include "type.h"

namespace systems {

SystemManager::SystemManager() {
    state_ = new Entity("globalState");
}

void SystemManager::AddSystem(System* system) {
    systems_.push_back(system);
    performance_.push_back(PerformanceData<std::chrono::microseconds>());
    system->PrintComponents();
}
void SystemManager::AddEntity(Entity* entity) {
    for (auto & [aspect, entities]: aspect_entities_) {
        if (aspect.IsFit(entity)) {
            entities.insert(entity);
        }
    }
}

void SystemManager::RemoveEntity(Entity* entity) {
    for (auto & [aspect, entities]: aspect_entities_) {
        if (entities.find(entity) != entities.end()
                && !aspect.IsFit(entity)) {
            entities.erase(entity);
        }
    }
}

std::chrono::microseconds SystemManager::MeasureTick(System* system, int dt) {
    auto start = std::chrono::high_resolution_clock::now();
    system->Tick(dt);
    auto finish = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
}

const std::set<Entity*>& SystemManager::GetAspectEntities(const Aspect& aspect) {
    assert(aspect_entities_.find(aspect) != aspect_entities_.end()
        && "Getting entities for aspect that's not registered");
    return aspect_entities_[aspect];
}
void SystemManager::RegisterAspect(const Aspect& aspect) {
    std::cerr << "Registering aspect: " << aspect.GetSignature() << std::endl; 
    aspect_entities_[aspect] = std::set<Entity*>();
}

const int PERFORMANCE_PERIOD = 5000;

void SystemManager::Tick(int dt) {
    for (size_t i = 0; i < systems_.size(); i++) {
        auto duration = MeasureTick(systems_[i], dt);
        performance_[i].Add(duration);
    }
    time_ += dt;
    if (time_ >= PERFORMANCE_PERIOD) {
        time_ -= PERFORMANCE_PERIOD;
        std::chrono::microseconds total(0);
        for (auto performance: performance_) {
            total += performance.GetAvg();
        }

        auto total_mu = total.count();
        std::cerr << "Total avg: "
            << total_mu << "mu" << std::endl;
        for (size_t i = 0; i < systems_.size(); i++) {
            auto system_mu = performance_[i].GetAvg().count();
            int percent = system_mu * 1.0 / total_mu * 100;
            std::cerr << "(" << systems_[i]->Name() << "): "
                << system_mu << "mu (" << percent << "%)" << std::endl;
        }
        std::cerr << std::endl;
    }

}

}
