#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include "threads.hpp"

void incrementCounter(Counter *counter)
{
    // std::cout << "Thread with id " << std::this_thread::get_id()<< " is waiting on the lock\n";
    auto t_start = std::chrono::steady_clock::now();

    counter->mutex.lock();
    std::cout << "Thread with id " << std::this_thread::get_id() << " acquired the lock" << std::endl;

    for (int i = 0; i < 1'000; i++)
    {
        counter->shared_counter++;
    }

    counter->mutex.unlock();
    auto t_stop = std::chrono::steady_clock::now();
    double t_delta = std::chrono::duration<double, std::micro>(t_stop - t_start).count();

    std::cout << "Thread with id " << std::this_thread::get_id() << " unlocked the mutex and exited the critical section" << std::endl;
    std::printf("Time needed to unlock the lock: %.3f us\n", t_delta);
}