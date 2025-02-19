#pragma once
#include <chrono>
#include <iostream>
#include <thread>

struct Benchmark
{
    std::string titel;
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::chrono::time_point<std::chrono::high_resolution_clock> end;

    Benchmark(const std::string &title) : titel(title)
    {
        // std::cout << "Benchmark: \"" << titel << "\" started." << std::endl;
        // for (int i = 3; i > 0; i--)
        // {
        //     std::cout << i << "...";
        //     std::this_thread::sleep_for(std::chrono::seconds(1));
        // }
        // std::cout << "go!n" << std::endl;
        start = std::chrono::high_resolution_clock::now();
    }

    ~Benchmark()
    {
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Benchmark: \"" << titel << "\" took "
                  << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
                  << " microseconds." << std::endl;
    }
};