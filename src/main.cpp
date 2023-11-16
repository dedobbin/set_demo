#include <iostream>
#include <string>
#include "set.h"

int main(int argc, char* argv[])
{
    Set set;
    const std::string target = "aaaa";
    set.add("peeppeeppe");
    std::cout << set;
    set.add(target);

    std::cout << "Set contains " << target << "? " << (set.contains(target) ? "yes" : "no") << std::endl;
    set.remove(target);
    std::cout << "Set contains " << target << "? " << (set.contains(target) ? "yes" : "no") << std::endl;
    return 0;   
}