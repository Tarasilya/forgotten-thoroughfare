#include "aspect.h"


std::string Aspect::MakeSignature(std::vector<std::string> type_names) {
    sort(type_names.begin(), type_names.end());
    std::string result = "";
    for (auto type_name: type_names) {
        result += type_name;
    }
    return result;
}

bool Aspect::IsFit(Entity* entity) const {
    return test_fitness_(entity);
}

const std::string& Aspect::GetId() const {
    return signature_;
}

bool Aspect::operator<(const Aspect& other) const {
    return signature_ < other.signature_;
}