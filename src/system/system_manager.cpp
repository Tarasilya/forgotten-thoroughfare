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
    performance_.push_back(PerformanceData<std::chrono::microseconds>());
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

std::chrono::microseconds SystemManager::MeasureTick(System* system, int dt) {
    auto start = std::chrono::high_resolution_clock::now();
    system->Tick(dt);
    auto finish = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
}

const int PERFORMANCE_PERIOD = 5000;

void SystemManager::Tick(int dt) {
    for (int i = 0; i < systems_.size(); i++) {
        auto duration = MeasureTick(systems_[i], dt);
        performance_[i].Add(duration);
//        std::cerr << duration.count() << " " << performance_[i].GetAvg().count() <<  std::endl;
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
        for (int i = 0; i < systems_.size(); i++) {
            auto system_mu = performance_[i].GetAvg().count();
            int percent = system_mu * 1.0 / total_mu * 100;
            std::cerr << "(" << systems_[i]->Name() << "): "
                << system_mu << "mu (" << percent << "%)" << std::endl;
        }
        std::cerr << std::endl;
    }

}

}
