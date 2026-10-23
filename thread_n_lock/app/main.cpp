#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
#include<vector>
#include"threads.hpp"


int main(int argc, char const *argv[])
{
    Counter counter;

    const uint32_t hw_threads = std::thread::hardware_concurrency();
    std::printf("Number of hw threads: %d\n", hw_threads);

    std::vector<std::thread> thread_vector;
    thread_vector.reserve(hw_threads);
    
    for (int i = 0; i < hw_threads; i++)
    {
        thread_vector.emplace_back(incrementCounter, &counter);
        //std::cout << "Spawned thread with id: " << thread_vector[i].get_id() << std::endl;
    }
    
    for(auto& thread : thread_vector){
        if (thread.joinable())
        {
            thread.join();
        }
    }

    std::cout << "Final counter value: " << counter.shared_counter << std::endl;

    return 0;
}
