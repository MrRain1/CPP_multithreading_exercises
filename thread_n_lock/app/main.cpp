#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include "threads.hpp"

int main()
{
    Counter counter;

    const uint32_t hw_threads = std::thread::hardware_concurrency();
    std::cout << "Number of hw threads: " << hw_threads << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    
    std::vector<std::thread> thread_vector;
    thread_vector.reserve(hw_threads);

    for (int i = 0; i < hw_threads; i++)
    {
        thread_vector.emplace_back(incrementCounter, &counter);
        // std::cout << "Spawned thread with id: " << thread_vector[i].get_id() << std::endl;
    }

    for (auto &thread : thread_vector)
    {
        if (thread.joinable())
        {
            thread.join();
        }
    }

    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "Final counter value: " << counter.shared_counter << std::endl;

    return 0;
}
