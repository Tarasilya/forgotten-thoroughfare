#pragma once

#include "entity.h"

#include <functional>
#include <string>
#include <vector>


class Aspect {
private:
    std::string signature_;
    std::function<bool(Entity*)> test_fitness_;

    static std::string MakeSignature(std::vector<std::string> type_names);

    template<class Component, class ...Components>
    static std::vector<std::string> GetTypeNames();
    template<class Component>
    static std::vector<std::string> GetTypeNames();


public:
    template<class ...Components>
    static Aspect CreateAspect();

    bool IsFit(Entity* entity) const;
    const std::string& GetId() const;
    bool operator<(const Aspect& other) const;
};


#include "type.h"

template<class Component, class ...Components>
std::vector<std::string> Aspect::GetTypeNames() {
    std::vector<std::string> type_names = GetTypeNames<Components...>();
    type_names.push_back(type<Component>());
    return type_names;
}

template<class Component>
std::vector<std::string> Aspect::GetTypeNames() {
    return std::vector<std::string>(1, type<Component>());
}

template<class ...Components>
Aspect Aspect::CreateAspect() {
    Aspect aspect;
    std::vector<std::string> type_names = GetTypeNames<Components...>();
    aspect.signature_ = MakeSignature(type_names);
    aspect.test_fitness_ 
        = [&type_names](Entity* entity) {
            for (auto type_name: type_names) {
                if (!entity->HasComponent(type_name)) {
                    return false;
                }
            }
            return true;
        };
    return aspect;
}
