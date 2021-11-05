#ifndef TOOLS_HPP
#define TOOLS_HPP

namespace ft
{
    //출저 : https://github.com/llefranc/42_ft_containers/blob/main/templates/stl_like.hpp

    //들어온 bool 이 false 일경우 아무 맴버가 없다. 따라서 이를 이용해 에러를 발생시킬 수 있고,
    //오버로드 함수 후보에서 제외 시킬 수 있다.
    //들어온 bool 값이 true 인경우에만 type 이라는 맴버를 갖는다.
    template <bool B>
    struct enable_if
    {
    };

    template <>
    struct enable_if<true>
    {
        typedef int type;
    };

    //bool , char, short 등 integer 로 바뀔수있는 것들에 대해서는 value 가 true, 아닐경우 false
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
