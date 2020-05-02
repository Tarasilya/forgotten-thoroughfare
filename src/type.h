#pragma once

#include <string>
#include <typeinfo>

template<class T>
std::string type() {
    return std::string(typeid(T).name());
}

template<class T>
std::string type(T expression) {
    return std::string(typeid(expression).name());
}
