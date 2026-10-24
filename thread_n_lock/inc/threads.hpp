#pragma once

#include<mutex>

struct Counter{
    uint32_t shared_counter = 0;
    std::mutex mutex;
};

void incrementCounter(Counter *counter);