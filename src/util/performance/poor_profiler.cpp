#include "poor_profiler.h"

#include <iostream>


std::vector<std::pair<const char*, PerformanceData<std::chrono::microseconds>>> PoorProfiler::data_;
int PoorProfiler::i_ = 0;
bool PoorProfiler::loop_ = false;
std::chrono::time_point<std::chrono::high_resolution_clock> PoorProfiler::last_ = std::chrono::high_resolution_clock::now();
std::string PoorProfiler::section_name_;

void PoorProfiler::Start(std::string name) {
    data_.clear(); 
    loop_ = false;
    i_ = 0;
    last_ = std::chrono::high_resolution_clock::now();
    section_name_ = name;
}

void PoorProfiler::MeasureSegment(const char* segment_name) {
    if (!loop_) {
        data_.push_back({segment_name, PerformanceData<std::chrono::microseconds>()});
    }
    auto cur = std::chrono::high_resolution_clock::now();
    data_[i_].second.Add(std::chrono::duration_cast<std::chrono::microseconds>(cur - last_));
    last_ = cur;
    i_++;
}

void PoorProfiler::EndSection() {
    loop_ = true;
    i_ = 0;
}

void PoorProfiler::FlushResults() {
    std::chrono::microseconds total(0);
    for (auto data: data_) {
        total += data.second.GetTotal();
    }

    std::cerr << "Total for " << section_name_ << ": "
        << total.count() << "mu" << std::endl;
    for (auto data: data_) {
        auto segment = data.second.GetTotal();
        int percent = segment * 1.0 / total * 100;
        std::cerr << "" << data.first << ": "
            << segment.count() << "mu" << " (" << percent << "%)" << std::endl;
    }
    std::cerr << std::endl;   
}
