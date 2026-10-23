#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
#include<vector>
#include"threads.hpp"

void incrementCounter(Counter *counter){
    //std::cout << "Thread with id " << std::this_thread::get_id()<< " is waiting on the lock\n";

    auto t_start = std::chrono::steady_clock::now();
    counter->mutex.lock();
    auto t_stop = std::chrono::steady_clock::now();

    double t_delta = std::chrono::duration<double, std::micro>(t_stop-t_start).count();

    std::cout << "Thread with id " << std::this_thread::get_id()<< " acquired the lock\n";
    std::printf("Time needed to acquire the lock: %.3f us\n", t_delta);

    for (int i = 0; i < 1e3; i++)
    {
        counter->shared_counter++;
    }

    t_start = std::chrono::steady_clock::now();
    counter->mutex.unlock();
    t_stop = std::chrono::steady_clock::now();
    t_delta = std::chrono::duration<double, std::micro>(t_stop-t_start).count();

    std::cout << "Thread with id " << std::this_thread::get_id()<< " unlocked the mutex and exited the critical section\n";
    std::printf("Time needed to unlock the lock: %.3f us\n", t_delta);
}