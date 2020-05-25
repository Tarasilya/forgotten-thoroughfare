#include "selected.h"


namespace component {

Selected::Selected(): when_(std::chrono::high_resolution_clock::now()) {}

std::chrono::time_point<std::chrono::high_resolution_clock> Selected::When() {
    return when_;
}

}
