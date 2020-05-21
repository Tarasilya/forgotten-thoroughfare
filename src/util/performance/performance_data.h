#pragma once

#include <chrono>
#include <deque>
#include <iostream>

template <class T>
class PerformanceData {
private:
    std::deque<T> durations_;
    size_t period_;
    T total_;

public:
    PerformanceData(size_t period = 60): period_(period) {
        total_ = T(0);
    }
    void Add(T duration) {
        total_ += duration;
        durations_.push_back(duration);
        if (durations_.size() > period_) {
            durations_.pop_front();
        }
    }
    T GetTotal() {
        return total_;
    }
    T GetAvg() {
        T result(0);
        for (auto duration: durations_) {
            result += duration;
        }
        return result / period_;
    }
};