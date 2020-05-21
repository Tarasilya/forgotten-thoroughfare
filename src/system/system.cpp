#include "system.h"

#include "entity.h"
#include "type.h"

#include <string>
#include <vector>


namespace systems {

System::System(SystemManager* manager, const std::string& name)
        : name_(name), system_manager_(manager) {
    std::cerr << std::endl << "(" << name << ")" << std::endl;
}

void System::PrintComponents() {
    std::cerr << "(" << name_ << ") used state: ";
    for (auto component: used_state_) {
        std::cerr << "{" << component << "}, ";
    }
    std::cerr << std::endl;
}

std::string System::Name() {
    return name_;
}

}
