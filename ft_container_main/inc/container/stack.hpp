#ifndef STACK_HPP
#define STACK_HPP

#include "./vector.hpp"

namespace ft
{
    template<typename T, class Container = ft::vector<T> >
    class stack
    {
    public:
        typedef T  value_type;
        typedef Container container_type;
        typedef size_t size_type;

    protected:
        container_type c;

        //===============================================================================
        //================================= Constructer =================================
        //===============================================================================

    public:

        explicit stack(const container_type& a = container_type()) : c(a) {}

        stack(const stack<T> &a) : c(a.c) {}
        stack<T>& operator=(const stack<T>& a) 
        {
            c = a.c; 
            return *this; 
        }
        ~stack() {}

        bool empty()
        {
            return c.empty();
        }

        size_type size()
        {
            return c.size();
        }

        value_type &top()
        {
            return c.back();
        }

        const value_type &top() const
        {
            return c.back();
        }
        
        void push(const value_type &value)
        {
            c.push_back(value);
        }

        void pop()
        {
          c.pop_back();
        }
        template <class TT, class CContainer>
        friend bool operator==(const stack<TT, CContainer>& x, const stack<TT, CContainer>& y);
        
        template <class TT, class CContainer>
        friend bool operator< (const stack<TT, CContainer>& x, const stack<TT, CContainer>& y);
        
        template <class TT, class CContainer>
        friend bool operator!=(const stack<TT, CContainer>& x, const stack<TT, CContainer>& y);
        
        template <class TT, class CContainer>
        friend bool operator> (const stack<TT, CContainer>& x, const stack<TT, CContainer>& y);
        
        template <class TT, class CContainer>
        friend bool operator>=(const stack<TT, CContainer>& x, const stack<TT, CContainer>& y);
        
        template <class TT, class CContainer>
        friend bool operator<=(const stack<TT, CContainer>& x, const stack<TT, CContainer>& y);
    };

    template <class T, class Container>
    bool operator==(const stack<T, Container>& x, const stack<T, Container>& y)
    {
        return (x.c == y.c);
    }

    template <class T, class Container>
    bool operator< (const stack<T, Container>& x, const stack<T, Container>& y)
    {
        return (x.c < y.c);
    }

    template <class T, class Container>
    bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y)
    {
        return (!(x.c == y.c));
    }

    template <class T, class Container>
    bool operator> (const stack<T, Container>& x, const stack<T, Container>& y)
    {
        return (x.c > y.c);
    }

    template <class T, class Container>
    bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y)
    {
        return (!(x.c < y.c));
    }

    template <class T, class Container>
    bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y)
    {
        return (!(x.c > y.c));
    }

};

#endif



/*

    this is stack's original synop. 

    stack synopsis

namespace std
{

template <class T, class Container = deque<T>>
class stack
{
public:
    typedef Container                                container_type;
    typedef typename container_type::value_type      value_type;
    typedef typename container_type::reference       reference;
    typedef typename container_type::const_reference const_reference;
    typedef typename container_type::size_type       size_type;

protected:
    container_type c;

public:
    stack() = default;
    ~stack() = default;

    stack(const stack& q) = default;
    stack(stack&& q) = default;

    stack& operator=(const stack& q) = default;
    stack& operator=(stack&& q) = default;

    explicit stack(const container_type& c);
    explicit stack(container_type&& c);
    template <class Alloc> explicit stack(const Alloc& a);
    template <class Alloc> stack(const container_type& c, const Alloc& a);
    template <class Alloc> stack(container_type&& c, const Alloc& a);
    template <class Alloc> stack(const stack& c, const Alloc& a);
    template <class Alloc> stack(stack&& c, const Alloc& a);

    bool empty() const;
    size_type size() const;
    reference top();
    const_reference top() const;

    void push(const value_type& x);
    void push(value_type&& x);
    template <class... Args> reference emplace(Args&&... args); // reference in C++17
    void pop();

    void swap(stack& c) noexcept(is_nothrow_swappable_v<Container>)
};

template<class Container>
  stack(Container) -> stack<typename Container::value_type, Container>;  // C++17

template<class Container, class Allocator>
  stack(Container, Allocator) -> stack<typename Container::value_type, Container>; // C++17

template <class T, class Container>
  bool operator==(const stack<T, Container>& x, const stack<T, Container>& y);
template <class T, class Container>
  bool operator< (const stack<T, Container>& x, const stack<T, Container>& y);
template <class T, class Container>
  bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y);
template <class T, class Container>
  bool operator> (const stack<T, Container>& x, const stack<T, Container>& y);
template <class T, class Container>
  bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y);
template <class T, class Container>
  bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y);

template <class T, class Container>
  void swap(stack<T, Container>& x, stack<T, Container>& y)
  noexcept(noexcept(x.swap(y)));

}  // std

*/