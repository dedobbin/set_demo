#include <cassert>
#include <iostream>
#include "tests/strategy/simple_strategy.h"
#include "set.h"
#include "strategy/simple_strategy.h"

void SimpleStrategyTest::add()
{
    std::cout << "Test SimpleStrategy - add()\n";
    
    Set set(new SimpleStrategy());
    
    assert(set.size() == 0);

    std::string str = "shdkfhjdhhdkf";
    set.add(str);
    assert(set.get_inner_cpy()[0] == str);
    
    assert(set.size() == 1);

    std::string str2 = "kdfkldsklj";
    set.add(str2);
    assert(set.get_inner_cpy()[1] == str2);
    
    assert(set.size() == 2);

    for (int i = 0; i < 100; i++){
        set.add(std::to_string(i));
    }

    assert(set.size() == 102);
}

void SimpleStrategyTest::contains()
{
    std::cout << "Test SimpleStrategy - contains()\n";
    
    Set set(new SimpleStrategy());
    std::string str = "shdkfhjdhhdkf";
    set.add(str);
    assert(set.contains(str));

    std::string str2 = "kdfkldsklj";
    set.add(str2);
    assert(set.contains(str2));
    
    for (int i = 0; i < 100; i++){
        set.add(std::to_string(i));
    }

    assert(set.size() == 102);

    assert(set.contains("32"));
    assert(set.contains("46"));
    assert(set.contains("12"));
}

void SimpleStrategyTest::remove()
{
    std::cout << "Test SimpleStrategy - remove()\n";
    
    Set set(new SimpleStrategy());
        
    std::string str = "shdkfhjdhhdkf";
    set.add(str);

    assert(set.size() == 1);

    std::string str2 = "kdfkldsklj";
    set.add(str2);

    set.remove(str);
    assert(set.get_inner_cpy()[0] == str2);

    assert(set.size() == 1);
    
    for (int i = 0; i < 100; i++){
        set.add(std::to_string(i));
    }

    assert(set.size() == 101);

    set.remove("32");
    set.remove("64");

    assert(set.size() == 99);

    assert(!set.contains("32"));
    assert(!set.contains("64"));
    assert(set.contains("12"));

}