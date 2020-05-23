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

public:
    template<class ...Components>
    static Aspect CreateAspect();

    bool IsFit(Entity* entity) const;
    bool operator<(const Aspect& other) const;
    const std::string& GetSignature() const;
};


#include "type.h"


template<class Component>
std::vector<std::string> GetTypeNames() {
    return std::vector<std::string>(1, type<Component>());
}
template<class Component1, class Component2, class ...Components>
std::vector<std::string> GetTypeNames() {
    std::vector<std::string> type_names;
    type_names = GetTypeNames<Component2, Components...>();
    type_names.push_back(type<Component1>());
    return type_names;
}

template<class ...Components>
Aspect Aspect::CreateAspect() {
    Aspect aspect;
    std::vector<std::string> type_names = GetTypeNames<Components...>();
    aspect.signature_ = MakeSignature(type_names);
    std::cerr << "new aspect: " << aspect.signature_ << std::endl;
    aspect.test_fitness_ 
        = [type_names](Entity* entity) {
            for (auto type_name: type_names) {
                if (!entity->HasComponent(type_name)) {
                    return false;
                }
            }
            return true;
        };
    return aspect;
}
