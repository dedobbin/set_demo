#include <iostream>
#include <string>
#include "set.h"
#include "tests/strategy/simple_strategy.h"
#include "tests/strategy/binary_search.h"

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

int main(int argc, char* argv[])
{
    //demo();
    tests();
    return 0;   
}