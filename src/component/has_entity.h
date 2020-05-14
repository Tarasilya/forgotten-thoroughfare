#pragma once

class Entity;

class HasEntity {
private:
    Entity* entity_ = 0;
public:
    void SetEntity(Entity* entity);
    Entity* GetEntity();
    void RemoveEntity();
};