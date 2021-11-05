#ifndef VECTOR_CPP
#define VECTOR_CPP

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <limits>
#include <string>

#include "container/vector.hpp"
#include "iterator/vector_iterator.hpp"
#include "tools.hpp"

namespace ft
{
    template <typename T, class Alloc = std::allocator<T> >
    class vector
    {

        //===============================================================================
        //=============================== Private & public ==============================
        //===============================================================================

    private:
        T *arr;
        size_t elem_num;
        size_t capa_num;
        Alloc allocer;

        //================================== Utility ===================================

        void expand(size_t target_size)
        {
            if (elem_num >= target_size)
                return;

            T *tmp = allocer.allocate(target_size);
            if (elem_num > 0)
            {
                for (size_t i = 0; i < elem_num; i++)
                    allocer.construct(tmp + i, *(arr + i));
                allocer.destroy(arr);
                allocer.deallocate(arr, elem_num);
            }
            capa_num = target_size;
            arr = tmp;
        }

        void set_value(T *pos, const T &val)
        {
            allocer.construct(pos, val);
        }

        unsigned int getIdxFromPtr(T *target)
        {
            return (target - arr);
        }

        void vec_pusher(T *pos, unsigned int expend_size)
        {
            unsigned int idx = getIdxFromPtr(pos);

            if (expend_size + elem_num >= capa_num)
                expand((2 * expend_size) + elem_num);

            for (unsigned int i = 0; i < elem_num - idx; i++)
                set_value(expend_size + arr + elem_num - 1 - i, *(arr + elem_num - 1 - i));
        
        }

        void vec_pusher_back(T *pos, unsigned int expend_size)
        {
            unsigned int idx = getIdxFromPtr(pos);

            for (unsigned int i = idx; i < elem_num - expend_size; i++)
                set_value(arr + i, *(arr + i + expend_size));
            elem_num -= expend_size;
        }

        class outRangeException : public std::exception
        {
            virtual const char *what() const throw()
            {
                return "this Index is out of range";
            }
        };

    public:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef value_type &reference;
        typedef const value_type &const_reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef T *pointer;
        typedef const T *const_pointer;

        typedef vectorIterator<T> iterator;
        typedef vectorIterator<const T> const_iterator;
        typedef ReverseIterator<T> reverse_iterator;
        typedef ReverseIterator<const T> reverse_const_iterator;

        //===============================================================================
        //================================= Constructer =================================
        //===============================================================================

        // [default constructer]
        explicit vector(const allocator_type &alloc_type = allocator_type()) : arr(NULL), elem_num(0), capa_num(0)
        {
            (void)alloc_type;
            expand(10);
        }

        // [fill constructer]
        explicit vector(size_type range, const value_type &val = value_type(), const allocator_type &alloc_type = allocator_type()) : arr(NULL), elem_num(0), capa_num(0)
        {
            (void)alloc_type;
            expand(10);
            for (size_type i = 0; i < range; i++)
                push_back(val);
        }

        // [range constructer]
        template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type &alloc_type = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type dum = 0) : arr(NULL), elem_num(0), capa_num(0)
        {
            (void)alloc_type;
            dum = 0;
            expand(10);
            for (InputIterator it = first; it != last; it++)
                push_back(*it);
        }

        // [copy constructer]
        vector(const vector &target) : arr(NULL), elem_num(0), capa_num(0)
        {
            expand(10);
            insert(begin(), target.begin(), target.end());
        }

        vector<T> &operator=(const vector &target)
        {
            clear();
            insert(begin(), target.begin(), target.end());
            return (*this);
        }

        ~vector()
        {
            allocer.destroy(arr);
            allocer.deallocate(arr, capa_num);
        }

        //===============================================================================
        //================================== iterator ===================================
        //===============================================================================
        iterator begin()
        {
            return (iterator(arr));
        }

        const_iterator begin() const
        {
            return (const_iterator(arr));
        }

        iterator end()
        {
            return (iterator(arr + elem_num));
        }

        const_iterator end() const
        {
            return (const_iterator(arr + elem_num));
        }

        reverse_iterator rbegin()
        {
            return (reverse_iterator(arr + elem_num - 1));
        }

        // const_reverse_iterator rbegin() const
        // {
        //     return (const_reverse_iterator (arr + elem_num - 1));
        // }

        reverse_iterator rend()
        {
            return (reverse_iterator(arr - 1));
        }

        // const_reverse_iterator rend() const
        // {
        //     return (const_reverse_iterator ( arr - 1 ));
        // }

        //===============================================================================
        //================================== capacity ===================================
        //===============================================================================

        size_type size() const
        {
            return (this->elem_num);
        }

        size_type max_size() const
        {
            return (this->allocer.max_size());
        }

        void resize(size_type n, value_type val = value_type())
        {
            unsigned int element_num = this->elem_num;
            unsigned int i = 0;
            if (element_num < n)
            {
                for (i = 0; i < n - element_num; i++)
                    push_back(val);
            }
            else
            {
                for (i = 0; i < element_num - n; i++)
                    pop_back();
            }
        }

        size_type capacity() const
        {
            return (this->capa_num);
        }

        bool empty() const
        {
            return (this->elem_num == 0);
        }

        void reserve(size_type expend_size)
        {
            if (this->elem_num < expend_size)
                expand(expend_size);
        }

        //===============================================================================
        //================================== elements ===================================
        //===============================================================================

        reference operator[](size_type n)
        {
            return (at(n));
        }

        const_reference operator[](size_type n) const
        {
            return (at(n));
        }

        reference at(size_type n)
        {
            if (n >= this->elem_num)
                throw outRangeException();
            else
                return arr[n];
        }

        const_reference at(size_type n) const
        {
            if (n >= this->elem_num)
                throw outRangeException();
            else
                return (arr[n]);
        }

        reference front()
        {
            return (at(0));
        }

        reference back()
        {
            return (at(elem_num - 1));
        }

        const_reference front() const
        {
            return (at(0));
        }

        const_reference back() const
        {
            return (at(elem_num - 1));
        }

        //===============================================================================
        //================================= functions ===================================
        //===============================================================================

        template <class InputIterator>
        void assign(InputIterator start, InputIterator end, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type dum = 0)
        {
            dum = 0;
            clear();
            unsigned int i = 0;
            for (InputIterator it = start; it != end; it++)
            {
                set_value(arr + i, *it);
                i++;
            }
            elem_num += i;
        }

        //@if_error : push_back이 괜찮은가?!
        void assign(size_type n, const value_type &val)
        {
            clear();
            unsigned int i = 0;
            for (i = 0; i < n; i++)
                push_back(val);
        }

        void clear()
        {
            elem_num = 0;
        }

        void pop_back()
        {
            if (elem_num > 0)
                --elem_num;
        }

        void push_back(const value_type &val)
        {
            if (elem_num == capa_num)
            {
                if (capa_num == 1)
                    expand(capa_num * 2);
                else
                    expand((capa_num * 2) - 3);
            }
            set_value(arr + elem_num, val);
            elem_num++;
        }

        template <class InputIterator>
        void insert(iterator target_pos, InputIterator begin, InputIterator end, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type dum = 0)
        {
            dum = 0;
            unsigned int len = 0;
            T *t_pos_ptr = target_pos.getPtr();
            for (InputIterator tmp = begin; tmp != end; tmp++)
                len++;

            vec_pusher(t_pos_ptr, len);

            unsigned int i = 0;
            // @if_error@ 혹시 삽입에 1정도 길이 차이가 나면 이 부분을 고쳐보쟈
            i = 0;
            for (InputIterator iter = begin; iter != end; iter++)
            {
                set_value((t_pos_ptr + i), *iter);
                i++;
            }
            elem_num += len;
        }

        void insert(iterator target_pos, size_type n, const value_type &val)
        {
            T *t_pos_ptr = target_pos.getPtr();
            vec_pusher(t_pos_ptr, n);
            for (unsigned int i = 0; i < n; i++)
                set_value(arr + i, val);
            this->elem_num += n;
        }

        iterator insert(iterator target_pos, const value_type &val)
        {
            T *t_pos_ptr = target_pos.getPtr();
            vec_pusher(t_pos_ptr, 1);
            set_value(t_pos_ptr, val);
            this->elem_num++;
            return (t_pos_ptr);
        }

        iterator erase(iterator pos)
        {
            unsigned int idx = getIndexFromPtr(pos.getPtr());

            vec_pusher_back(pos.getPtr(), 1);
            return (iterator(arr + idx));
        }

        iterator erase(iterator start, iterator end)
        {
            unsigned int idx = getIndexFromPtr(start.getPtr());

            unsigned int i = 0;
            for (iterator it = start; it != end; it++)
                i++;
            vec_pusher_back(start.getPtr(), i);

            return (iterator(arr + idx));
        }

        void swap(vector &x)
        {
            T *tmp = this->arr;
            this->arr = x.arr;
            x.arr = tmp;

            unsigned int tmp_elem_num = this->elem_num;
            this->elem_num = x.elem_num;
            x.elem_num = tmp_elem_num;

            unsigned int tmp_capa_num = this->capa_num;
            this->capa_num = x.capa_num;
            x.capa_num = tmp_capa_num;
        }
    };


        //===============================================================================
        //================================= overload ===================================
        //===============================================================================

    template <class T, class Alloc>
    bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        if (lhs.size() != rhs.size())
            return false;
        return equal(lhs.begin(), lhs.end(), rhs.begin());
    }

    template <class T, class Alloc>
    bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return (!(lhs == rhs));
    }

    template <class T, class Alloc>
    bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return lexicographical_less(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <class T, class Alloc>
    bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return ((lhs == rhs) || (lhs < rhs));
    }

    template <class T, class Alloc>
    bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return (!(lhs <= rhs));
    }

    template <class T, class Alloc>
    bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return ((lhs == rhs) || (lhs > rhs));
    }

    template <class T, class Alloc>
    void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
    {
        x.swap(y);
    }
}

#endif
/*

    -> the STD vector library's text references below,  



    vector synopsis

namespace std
{

template <class T, class Allocator = allocator<T> >
class vector
{
public:
    typedef T                                        value_type;
    typedef Allocator                                allocator_type;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef implementation-defined                   iterator;
    typedef implementation-defined                   const_iterator;
    typedef typename allocator_type::size_type       size_type;
    typedef typename allocator_type::difference_type difference_type;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;
    typedef std::reverse_iterator<iterator>          reverse_iterator;
    typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;

    vector()
        noexcept(is_nothrow_default_constructible<allocator_type>::value);
    explicit vector(const allocator_type&);
    explicit vector(size_type n);
    explicit vector(size_type n, const allocator_type&); // C++14
    vector(size_type n, const value_type& value, const allocator_type& = allocator_type());
    template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type& = allocator_type());
    vector(const vector& x);
    vector(vector&& x)
        noexcept(is_nothrow_move_constructible<allocator_type>::value);
    vector(initializer_list<value_type> il);
    vector(initializer_list<value_type> il, const allocator_type& a);
    ~vector();
    vector& operator=(const vector& x);
    vector& operator=(vector&& x)
        noexcept(
             allocator_type::propagate_on_container_move_assignment::value ||
             allocator_type::is_always_equal::value); // C++17
    vector& operator=(initializer_list<value_type> il);
    template <class InputIterator>
        void assign(InputIterator first, InputIterator last);
    void assign(size_type n, const value_type& u);
    void assign(initializer_list<value_type> il);

    allocator_type get_allocator() const noexcept;

    iterator               begin() noexcept;
    const_iterator         begin()   const noexcept;
    iterator               end() noexcept;
    const_iterator         end()     const noexcept;

    reverse_iterator       rbegin() noexcept;
    const_reverse_iterator rbegin()  const noexcept;
    reverse_iterator       rend() noexcept;
    const_reverse_iterator rend()    const noexcept;

    const_iterator         cbegin()  const noexcept;
    const_iterator         cend()    const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend()   const noexcept;

    size_type size() const noexcept;
    size_type max_size() const noexcept;
    size_type capacity() const noexcept;
    bool empty() const noexcept;
    void reserve(size_type n);
    void shrink_to_fit() noexcept;

    reference       operator[](size_type n);
    const_reference operator[](size_type n) const;
    reference       at(size_type n);
    const_reference at(size_type n) const;

    reference       front();
    const_reference front() const;
    reference       back();
    const_reference back() const;

    value_type*       data() noexcept;
    const value_type* data() const noexcept;

    void push_back(const value_type& x);
    void push_back(value_type&& x);
    template <class... Args>
        reference emplace_back(Args&&... args); // reference in C++17
    void pop_back();

    template <class... Args> iterator emplace(const_iterator position, Args&&... args);
    iterator insert(const_iterator position, const value_type& x);
    iterator insert(const_iterator position, value_type&& x);
    iterator insert(const_iterator position, size_type n, const value_type& x);
    template <class InputIterator>
        iterator insert(const_iterator position, InputIterator first, InputIterator last);
    iterator insert(const_iterator position, initializer_list<value_type> il);

    iterator erase(const_iterator position);
    iterator erase(const_iterator first, const_iterator last);

    void clear() noexcept;

    void resize(size_type sz);
    void resize(size_type sz, const value_type& c);

    void swap(vector&)
        noexcept(allocator_traits<allocator_type>::propagate_on_container_swap::value ||
                 allocator_traits<allocator_type>::is_always_equal::value);  // C++17

    bool __invariants() const;
};

template <class Allocator = allocator<T> >
class vector<bool, Allocator>
{
public:
    typedef bool                                     value_type;
    typedef Allocator                                allocator_type;
    typedef implementation-defined                   iterator;
    typedef implementation-defined                   const_iterator;
    typedef typename allocator_type::size_type       size_type;
    typedef typename allocator_type::difference_type difference_type;
    typedef iterator                                 pointer;
    typedef const_iterator                           const_pointer;
    typedef std::reverse_iterator<iterator>          reverse_iterator;
    typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;

    class reference
    {
    public:
        reference(const reference&) noexcept;
        operator bool() const noexcept;
        reference& operator=(const bool x) noexcept;
        reference& operator=(const reference& x) noexcept;
        iterator operator&() const noexcept;
        void flip() noexcept;
    };

    class const_reference
    {
    public:
        const_reference(const reference&) noexcept;
        operator bool() const noexcept;
        const_iterator operator&() const noexcept;
    };

    vector()
        noexcept(is_nothrow_default_constructible<allocator_type>::value);
    explicit vector(const allocator_type&);
    explicit vector(size_type n, const allocator_type& a = allocator_type()); // C++14
    vector(size_type n, const value_type& value, const allocator_type& = allocator_type());
    template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type& = allocator_type());
    vector(const vector& x);
    vector(vector&& x)
        noexcept(is_nothrow_move_constructible<allocator_type>::value);
    vector(initializer_list<value_type> il);
    vector(initializer_list<value_type> il, const allocator_type& a);
    ~vector();
    vector& operator=(const vector& x);
    vector& operator=(vector&& x)
        noexcept(
             allocator_type::propagate_on_container_move_assignment::value ||
             allocator_type::is_always_equal::value); // C++17
    vector& operator=(initializer_list<value_type> il);
    template <class InputIterator>
        void assign(InputIterator first, InputIterator last);
    void assign(size_type n, const value_type& u);
    void assign(initializer_list<value_type> il);

    allocator_type get_allocator() const noexcept;

    iterator               begin() noexcept;
    const_iterator         begin()   const noexcept;
    iterator               end() noexcept;
    const_iterator         end()     const noexcept;

    reverse_iterator       rbegin() noexcept;
    const_reverse_iterator rbegin()  const noexcept;
    reverse_iterator       rend() noexcept;
    const_reverse_iterator rend()    const noexcept;

    const_iterator         cbegin()  const noexcept;
    const_iterator         cend()    const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend()   const noexcept;

    size_type size() const noexcept;
    size_type max_size() const noexcept;
    size_type capacity() const noexcept;
    bool empty() const noexcept;
    void reserve(size_type n);
    void shrink_to_fit() noexcept;

    reference       operator[](size_type n);
    const_reference operator[](size_type n) const;
    reference       at(size_type n);
    const_reference at(size_type n) const;

    reference       front();
    const_reference front() const;
    reference       back();
    const_reference back() const;

    void push_back(const value_type& x);
    template <class... Args> reference emplace_back(Args&&... args);  // C++14; reference in C++17
    void pop_back();

    template <class... Args> iterator emplace(const_iterator position, Args&&... args);  // C++14
    iterator insert(const_iterator position, const value_type& x);
    iterator insert(const_iterator position, size_type n, const value_type& x);
    template <class InputIterator>
        iterator insert(const_iterator position, InputIterator first, InputIterator last);
    iterator insert(const_iterator position, initializer_list<value_type> il);

    iterator erase(const_iterator position);
    iterator erase(const_iterator first, const_iterator last);

    void clear() noexcept;

    void resize(size_type sz);
    void resize(size_type sz, value_type x);

    void swap(vector&)
        noexcept(allocator_traits<allocator_type>::propagate_on_container_swap::value ||
                 allocator_traits<allocator_type>::is_always_equal::value);  // C++17
    void flip() noexcept;

    bool __invariants() const;
};

template <class InputIterator, class Allocator = allocator<typename iterator_traits<InputIterator>::value_type>>
   vector(InputIterator, InputIterator, Allocator = Allocator())
   -> vector<typename iterator_traits<InputIterator>::value_type, Allocator>;

template <class Allocator> struct hash<std::vector<bool, Allocator>>;

template <class T, class Allocator> bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator> bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator> bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator> bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator> bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator> bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

template <class T, class Allocator>
void swap(vector<T,Allocator>& x, vector<T,Allocator>& y)
    noexcept(noexcept(x.swap(y)));

template <class T, class Allocator, class U>
typename vector<T, Allocator>::size_type
erase(vector<T, Allocator>& c, const U& value);       // C++20
template <class T, class Allocator, class Predicate>
typename vector<T, Allocator>::size_type
erase_if(vector<T, Allocator>& c, Predicate pred);    // C++20

}  // std

*/