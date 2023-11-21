#include <random>
#include "benchmarks/strategy_benchmark.h"
#include "timer.h"
#include "set.h"


int64_t StrategyBenchmark::add(Strategy* strategy, int n_loops) 
{
    std::random_device rd;
    std::mt19937 random_gen(rd());
    std::uniform_int_distribution<int> range(0, 100000);

    Set set(strategy);

    Timer::start();
    for (int i = 0; i < n_loops; i++){
        set.add(std::to_string(range(random_gen)));
    }

    int64_t ms = Timer::end();
    return ms;
}

int64_t StrategyBenchmark::contains(Strategy* strategy, int n_loops) 
{
    std::random_device rd;
    std::mt19937 random_gen(rd());
    std::uniform_int_distribution<int> range(0, 100000);

    Set set(strategy);
    // TODO: faster way to insert
    for (int i = 0; i < n_loops; i++){
        set.add(std::to_string(range(random_gen)));
    }

    Timer::start();

    for (int i = 0; i < n_loops; i++){
        // TODO: make sure this gets not optimized away
        set.contains(std::to_string(range(random_gen)));
    }

    int64_t ms = Timer::end();
    return ms;
}

int64_t StrategyBenchmark::remove(Strategy* strategy, int n_loops) 
{
    std::random_device rd;
    std::mt19937 random_gen(rd());
    std::uniform_int_distribution<int> range(0, 100000);

    Set set(strategy);
    // TODO: faster way to insert
    for (int i = 0; i < n_loops; i++){
        set.add(std::to_string(range(random_gen)));
    }

    Timer::start();

    for (int i = 0; i < n_loops; i++){
        // TODO: make sure this gets not optimized away
        set.contains(std::to_string(range(random_gen)));
    }


    int64_t ms = Timer::end();
    return ms;
}