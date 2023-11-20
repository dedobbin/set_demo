#include <cassert>
#include <iostream>
#include "tests/strategy/binary_search.h"
#include "set.h"
#include "strategy/binary_search.h"

void BinarySearchTest::add()
{
    std::cout << "Test BinarySearchTest - add()\n";
    
    Set set(new BinarySearch());
    
    assert(set.size() == 0);

    std::string str = "aaaaa";
    set.add(str);
    assert(set.get_inner_cpy()[0] == str);
    
    assert(set.size() == 1);

    std::string str2 = "bbbbb";
    set.add(str2);
    assert(set.get_inner_cpy()[1] == str2);
    
    assert(set.size() == 2);

    for (int i = 0; i < 100; i++){
        set.add(std::to_string(i));
    }

    assert(set.size() == 102);
}

void BinarySearchTest::contains()
{
    std::cout << "Test BinarySearchTest - contains()\n";
    
    Set set(new BinarySearch());
    std::string str = "shdkfhjdhhdkf";
    set.add(str);
    assert(set.contains(str));

    std::string str2 = "kdfkldsklj";
    set.add(str2);
    

    for (int i = 0; i < 100; i++){
        set.add(std::to_string(i));
    }

    assert(set.size() == 102);
    
    assert(set.contains("32"));
    assert(set.contains("46"));
    assert(set.contains("12"));
}

void BinarySearchTest::remove()
{
    std::cout << "Test BinarySearchTest - remove()\n";
    
    Set set(new BinarySearch());
    
    assert(set.size() == 0);
    
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

    set.remove("3");
    set.remove("32");
    set.remove("64");

    assert(set.size() == 98);

    assert(!set.contains("3"));
    assert(!set.contains("32"));
    assert(!set.contains("64"));
    assert(set.contains("12"));
}

void BinarySearchTest::order()
{
    std::cout << "Test BinarySearchTest - order()\n";
    
    Set set(new BinarySearch());

    std::string str1 = "bb";
    std::string str2 = "aa";
    std::string str3 = "cc";
    set.add(str1);
    set.add(str2);
    set.add(str3);

    assert(set.get_inner_cpy()[0] == str2);
    assert(set.get_inner_cpy()[1] == str1);
    assert(set.get_inner_cpy()[2] == str3);

    Set set2(new BinarySearch());
    for (int i = 100; i > 0; i--){
        set2.add(std::to_string(i));
    }

    assert(set2.get_inner_cpy()[0] == "1");
    assert(set2.get_inner_cpy()[1] == "10");
    assert(set2.get_inner_cpy()[2] == "100");
    assert(set2.get_inner_cpy()[3] == "11");
}