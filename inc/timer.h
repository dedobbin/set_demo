#include <chrono>
#include <iostream>

static std::chrono::_V2::system_clock::time_point start_time;

namespace Timer
{
    void inline start(){
        start_time = std::chrono::high_resolution_clock::now();
    }

    int64_t inline end(bool do_print = false){
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
        int64_t counted = duration.count();
        if (do_print)
            std::cout << "Timed: " << counted << " microseconds" << std::endl;
        return counted;
    }
}