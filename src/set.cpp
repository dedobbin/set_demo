#include <iostream>
#include "set.h"

Set::Set()
{
    strategy = std::make_unique<SimpleStrategy>();
}

Set::Set(Strategy* init_strategy)
{
    // Take ownership
    strategy = std::unique_ptr<Strategy>(init_strategy);
}

void Set::add(std::string element)
{
    strategy->add(inner, element);
}

bool Set::contains(std::string element) const
{
    int index = strategy->find(inner, element);
    return index >= 0;
}

void Set::remove(std::string element)
{
    int index = strategy->find(inner, element);
    inner.erase(inner.begin() + index);

}

int Set::size() const
{
    return inner.size();
}

std::vector<std::string> Set::get_inner_cpy() const
{
    // TODO: make sure it's copied lol
    return inner;
}

std::ostream& operator<<(std::ostream& os, const Set& set) {
    for (std::string element : set.inner){
        os << element << std::endl;
    }
    return os;
}

