#pragma once

#include "collision_detection.h"

#include <vector>

class Entity;

template<int N>
class CollisionGrid {
private:
    std::vector<Entity*> grid_[N][N];
    double world_size_;
    double cell_size_;
public:
    CollisionGrid(double world_size): world_size_(world_size), cell_size_(world_size / N) {}
    void Add(Entity* entity) {
        auto rect = systems::CollisionDetection::GetMovedRect(entity);
        rect = rect.Move(world_size_ / 2, world_size_ / 2);
        int i1 = rect.y1 / cell_size_;
        int i2 = rect.y2 / cell_size_;
        int j1 = rect.x1 / cell_size_;
        int j2 = rect.x2 / cell_size_;
        i1 = std::max(0, i1);
        j1 = std::max(0, j1);
        i2 = std::min(N - 1, i2);
        j2 = std::min(N - 1, j2);
        for (int i = i1; i <= i2; i++) {
            for (int j = j1; j <= j2; j++) {
                grid_[i][j].push_back(entity);
            }
        }
    }
    std::vector<std::vector<Entity*>> GetPotentialCollisions(Entity* entity) {
        auto rect = systems::CollisionDetection::GetMovedRect(entity);
        rect = rect.Move(world_size_ / 2, world_size_ / 2);
        int i1 = rect.y1 / cell_size_;
        int i2 = rect.y2 / cell_size_;
        int j1 = rect.x1 / cell_size_;
        int j2 = rect.x2 / cell_size_;
        i1 = std::max(0, i1);
        j1 = std::max(0, j1);
        i2 = std::min(N - 1, i2);
        j2 = std::min(N - 1, j2);
        // if (entity->Name() == "mouse") {
        //     std::cerr << i1 << " " << i2 << " " 
        //         << j1 << " " << j2 << std::endl;
        // }

        std::vector<std::vector<Entity*>> result;
        for (int i = i1; i <= i2; i++) {
            for (int j = j1; j <= j2; j++) {
                // if (entity->Name() == "mouse") {
                //     std::cerr << "sz: " << grid_[i][j].size() << std::endl;
                // }
                result.push_back(grid_[i][j]);
            }
        }
        return result;    
    }
};