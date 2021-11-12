#ifndef PAIR_HPP
#define PAIR_HPP

#include "../tools.hpp"
namespace ft
{
    template<class T1, class T2>
    class pair
    {
        public:
            T1 first;
            T2 second; 

            typedef T1 first_type;
            typedef T2 second_type;

            //===============================================================================
            //================================= Constructer =================================
            //===============================================================================
            pair() : first(), second() {}

            pair(const T1& param_first, const T2& param_second) : first(param_first), second(param_second)
            {

            }

            pair(const pair<T1, T2>& original) : first(original.first), second(original.second) 
            {

            }

            pair(const pair &target)
            {
                this.first = target.first;
                this.second = target.second;
            }

            pair &operator=(const pair &target)
            {
                this.first = target.first;
                this.second = target.second;
                return (*this);
            }

            ~pair() {}

            //===============================================================================
            //================================= functions ===================================
            //===============================================================================

            first()
            {
                return this->first;
            }

            second()
            {
                return this->second;
            }
    };

    //===============================================================================
    //================================= overload ===================================
    //===============================================================================

    template <class _T1, class _T2>
    bool operator==(const pair<_T1, _T2> &lhs, const pair<_T1, _T2> &rhs)
    {
        return ((lhs.first == rhs.first) && (lhs.second == rhs.second));
    }

    //===============================================================================
    //================================= out func ===================================
    //===============================================================================

    template <class _T1, class _T2>
    pair<_T1, _T2> make_pair(_T1 _first, _T2 _second)
    {
        return pair<_T1, _T2>(_first, _second);
    }


    template<class Key, class Val, class Compare = less<Key> >
    class node
    {

        //===============================================================================
        //=============================== Private & public ==============================
        //===============================================================================

        private:
            // 0: red, 1: black, 2: Unknown
            int     color;
            node    *left;
            node    *right;
            node    *parent;
            Compare cmp;

        public:
            pair<Key, Val> set;

        //===============================================================================
        //================================= Constructer =================================
        //===============================================================================

        node() : left(NULL), right(NULL), parent(NULL), color(2), set(NULL)
        {
        }

        node(const pair<Key, Val> _set) : left(NULL), right(NULL), parent(NULL), color(2);
        {
            this->set = _set;
        }

        ~node()
        {
        }

        //===============================================================================
        //================================= functions ===================================
        //===============================================================================



    };

    template<class T>
    struct less
    {
        bool operator()( const T& lhs, const T& rhs ) const;
        {
            return lhs < rhs;
        }
    };
}


#endif