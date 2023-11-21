#include <iostream>
#include <string>
#include "set.h"
#include "strategy/binary_search.h"
#include "tests/strategy_test.h"
#include "benchmarks/strategy_benchmark.h"


void demo()
{
    Set set;
    const std::string target = "aaaa";
    set.add("peeppeeppe");
    std::cout << set;
    set.add(target);

    std::cout << "Set contains " << target << "? " << (set.contains(target) ? "yes" : "no") << std::endl;
    set.remove(target);
    std::cout << "Set contains " << target << "? " << (set.contains(target) ? "yes" : "no") << std::endl;
}

void tests()
{
    std::cout << "Running tests.." << std::endl;
    
    StrategyTest::add(new SimpleStrategy());
    StrategyTest::contains(new SimpleStrategy());
    StrategyTest::remove(new SimpleStrategy());
    StrategyTest::add_no_duplicates(new SimpleStrategy());

    StrategyTest::add(new BinarySearch());
    StrategyTest::contains(new BinarySearch());
    StrategyTest::remove(new BinarySearch());
    StrategyTest::add_no_duplicates(new BinarySearch());
}

void benchmarks()
{
    std::cout << "Running benchmarks.." << std::endl;

    int n = 10000;
    int ms1 = StrategyBenchmark::add(new SimpleStrategy(), n);
    int ms2 = StrategyBenchmark::add(new BinarySearch(), n);
    std::cout << "Add: "<< ms1 << " vs " << ms2 << " ms" << std::endl;

    ms1 = StrategyBenchmark::contains(new SimpleStrategy(), n);
    ms2 = StrategyBenchmark::contains(new BinarySearch(), n);
    std::cout << "Contains: "<< ms1 << " vs " << ms2 << " ms" << std::endl;

    ms1 = StrategyBenchmark::remove(new SimpleStrategy(), n);
    ms2 = StrategyBenchmark::remove(new BinarySearch(), n);
    std::cout << "Remove: "<< ms1 << " vs " << ms2 << " ms" << std::endl;
}

int main(int argc, char* argv[])
{
    //demo();
    tests();

    benchmarks();
    return 0;   
}