#include <iostream>
#include <string>
#include "set.h"
#include "strategy/binary_search.h"
#include "tests/strategy/simple_strategy.h"
#include "tests/strategy/binary_search.h"
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
    SimpleStrategyTest::add();
    SimpleStrategyTest::contains();
    SimpleStrategyTest::remove();

    BinarySearchTest::add();
    BinarySearchTest::contains();
    BinarySearchTest::remove();
    BinarySearchTest::order();
}

void benchmarks()
{
    int n = 1000;
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
    //tests();

    benchmarks();
    return 0;   
}