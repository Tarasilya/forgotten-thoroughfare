#pragma once

#include "performance_data.h"

#include <chrono>
#include <string>
#include <vector>


class PoorProfiler {
private:
    static std::vector<std::pair<const char*, PerformanceData<std::chrono::microseconds>>> data_;
    static int i_;
    static bool loop_;
    static std::chrono::time_point<std::chrono::high_resolution_clock> last_;
    static std::string section_name_;

public:
    static void Start(std::string name);
    static void MeasureSegment(const char* segment_name);
    static void EndSection();
    static void FlushResults();
};