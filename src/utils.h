//
// Created by zzhou on 11.11.20.
//

#ifndef LEETCODE_UTILS_H
#define LEETCODE_UTILS_H
#include <iostream>
#include <chrono>

// measure running time
// source: https://stackoverflow.com/questions/2808398/easily-measure-elapsed-time
// usage: std::cout << measure<>::execution(functor(dummy)) << std::endl;
template<typename TimeT = std::chrono::milliseconds>
struct measure
{
    template<typename F, typename ...Args>
    static typename TimeT::rep execution(F&& func, Args&&... args)
    {
        auto start = std::chrono::steady_clock::now();
        std::forward<decltype(func)>(func)(std::forward<Args>(args)...);
        auto duration = std::chrono::duration_cast<TimeT>(std::chrono::steady_clock::now() - start);
        return duration.count();
    }
};


#endif //LEETCODE_UTILS_H
