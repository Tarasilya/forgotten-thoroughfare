#pragma once

#include <chrono>
#include <deque>
#include <iostream>

template <class T>
class PerformanceData {
private:
    std::deque<T> durations_;
    int period_;

public:
    PerformanceData(int period = 60): period_(period) {}

    void Add(T duration) {
        durations_.push_back(duration);
        if (durations_.size() > period_) {
            durations_.pop_front();
        }
    }
    T GetAvg() {
        T result(0);
        for (auto duration: durations_) {
            result += duration;
        }
        return result / period_;
    }
};