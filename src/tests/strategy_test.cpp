#include <iostream>
#include "tests/strategy_test.h"
#include "set.h"
#include "assert.h"

void StrategyTest::add(Strategy* strategy)
{    
    Set set(strategy);
    
    assert(set.size() == 0);

    std::string str = "shdkfhjdhhdkf";
    set.add(str);
    
    assert(set.size() == 1);

    std::string str2 = "kdfkldsklj";
    set.add(str2);
    
    assert(set.size() == 2);

    for (int i = 0; i < 100; i++){
        set.add(std::to_string(i));
    }

    assert(set.size() == 102);
}

void StrategyTest::contains(Strategy* strategy)
{    
    Set set(strategy);
    std::string str = "shdkfhjdhhdkf";
    set.add(str);
    assert(set.contains(str));

    std::string str2 = "kdfkldsklj";
    set.add(str2);
    assert(set.contains(str2));
    
    for (int i = 0; i < 100; i++){
        set.add(std::to_string(i));
    }

    assert(set.contains("32"));
    assert(set.contains("46"));
    assert(set.contains("12"));
}

void StrategyTest::remove(Strategy* strategy)
{
    Set set(strategy);
        
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

void StrategyTest::add_no_duplicates(Strategy* strategy)
{
    Set set(strategy);
    std::string str = "shdkfhjdhhdkf";
    set.add(str);
    set.add(str);
    set.add(str);

    assert(set.size() == 1);
}