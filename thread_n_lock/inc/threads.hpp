#pragma once

#include<mutex>

typedef struct Counter{
    uint32_t shared_counter = 0;
    std::mutex mutex;
}Counter;

void incrementCounter(Counter *counter);