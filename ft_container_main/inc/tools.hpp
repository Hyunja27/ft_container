#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <iostream>

template <typename T>

void print_T(T a, int length)
{
    std::cout << '<' << typeid(a).name() << "> : ";

    for (int i = 0; i < length; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

#endif
