#ifndef TOOLS_HPP
#define TOOLS_HPP

namespace ft
{

    template <bool B>
    struct enable_if
    {
    };

    template <>
    struct enable_if<true>
    {
        typedef int type;
    };

    template <typename T>
    struct is_integral
    {
        static const bool value = false;
    };

    template <>
    struct is_integral<bool>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<char>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<short>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<int>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<long>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<long long>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned char>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned short>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned int>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned long>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned long long>
    {
        static const bool value = true;
    };

    template <typename T>
    struct less
    {
        bool operator()(const T &lhs, const T &rhs) const
        {
            return lhs < rhs;
        }
    };

    template <typename Input1, typename Input2>
    bool equal(Input1 it1_start, Input1 it1_end, Input2 it2_start)
    {
        while (it1_start != it1_end)
        {
            if (*it1_start != *it2_start)        
                return false;
            it1_start++;
            it2_start++;
        }
        return true;
    };

    template<typename Input1, typename Input2>
    bool lexicographical_compare(Input1 it1_start, Input1 it1_end, Input2 it2_start, Input2 it2_end)
    {
        while (it1_start != it1_end && it2_start != it2_end)
        {
            if (*it1_start < *it2_start)
                return true;
            else if (*it1_start > *it2_start)
                return false;
            it1_start++;
            it2_start++;
        }
        return it1_start == it1_end && it2_start != it2_end;
    }
}

template <typename T>
void print_T(T a, int length)
{
    // std::cout << '<' << typeid(a).name() << "> : ";

    for (int i = 0; i < length; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

#endif
