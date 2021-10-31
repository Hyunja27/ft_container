#ifndef VECTOR_CPP
#define VECTOR_CPP

#include <iostream>
#include <vector>

#include "../iterator/vector_iterator.hpp"
#include "../tools.hpp"

namespace ft {

    template <typename T, class Alloc = std::allocator<T> >
    class vector {

        //===============================================================================
        //=============================== Private & public ==============================
        //===============================================================================

        private:
            T*  arr;
            size_t elem_num;
            size_t capa_num;

        //================================== Utility ===================================

        void expand(long target_size)
        {
            if (elem_num >= target_size)
                return ;
            
            Alloc allocer;

            T* tmp = allocer.allocate(target_size);
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

        void set_value(T* pos, const t& val)
        {
            Alloc allocer;

            allocer.construct(pos, val);
        }

        unsigned int getIndexFromPtr(T* target)
        {
            return (target - arr);
        }

        void vec_pusher(T* pos, unsigned int expend_size)
        {
            Alloc allocer;
            unsigned int idx = getIdxFromPtr(pos);

            if (expand_size + elem_num >= capa_num)
                expand( (2 * expend_size) + elem_num);
            
            for (unsigned int i = 0; i < elem_num - idx; i++;)
                set_value(expend_size + arr + elem_num - 1 - i,  *(arr + elem_num - 1 - i));

        }


        public:
            typedef T value_type;
            typedef Alloc allocator_type;
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef size_t size_type;
            typedef ptrdiff_t difference_type;
            typedef T* pointer;
            typedef const T* pointer;

            typedef vector_iterator<T> iterator;
            typedef vector_C_iterator<T> const_iterator;
            typedef vector_R_iterator<T> reverse_iterator;
            typedef vector_CR_iterator<T> const_reverse_iterator;

        //===============================================================================
        //================================= Constructer =================================
        //===============================================================================

        // [default constructer]
        explicit vector (const allocator_type& alloc_type = allocator_type) : arr(NULL), elem_num(0), capa_num(0)
        {
            (void)alloc_type;
        }

        // [fill constructer]
        explicit vector (size_type range, const value_type& val = value_type, const allocator_type& alloc_type = allocator_type) : arr(NULL), capa_num(0), elem_num(0) 
        {
            (void)alloc_type;
            for (size_type i = 0; i < range; i++)
                push_back(val);
        }

        // [range constructer]
        template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type& alloc_type = allocator_type, typename ft::enable_if<ft::is_integral<InputIterator>::value >::type dum = 0 ) : arr(NULL), capa_num(0), elem_num(0)
        {
            (void)alloc_type;
            dum = 0;
            for (InputIterator it = first; it != last; it++)
                push_back(*it);
        }

        // [copy constructer]
        vector (const vector& target) : arr(NULL), capa_num(0), elem_num(0)
        {
            insert(begin(), target.begin(), target.end());
        }

        vector<T>& operator= (const vector& target)
        {
            clear();
            insert(begin(), target.begin(), target.end());
            return (*this);
        }

        ~vector()
        {
            Alloc allcer;

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

        const_reverse_iterator rbegin() const
        {
            return (const_reverse_iterator (arr + elem_num - 1));
        }

        reverse_iterator rend()
        {
            return (reverse_iterator ( arr - 1 ));
        }

        const_reverse_iterator rend()
        {
            return (const_reverse_iterator ( arr - 1 ));
        }

        //===============================================================================
        //================================== capacity ===================================
        //===============================================================================

        size_type size() const
        {
            return (this->elem_num);
        }

        size_type max_size() const
        {
            Alloc allocer;

            return (allocer.max_size());
        }

        void resize (size_type n, value_type val = value_type)
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



        //===============================================================================
        //================================== elements ===================================
        //===============================================================================


        //===============================================================================
        //================================= functions ===================================
        //===============================================================================

        void elem_num_clear()
        {
            elem_num = 0;
        }

        void pop_back()
        {
            if (elem_num > 0)
                --elem_num;
        }
`
        void push_back(const value_type& val)
        {
            if (elem_num == capa_num)
                expand(capa_num + 1);
            set_value(arr + elem_num, val);
            elem_num++;
        }

        template <InputIterator>
        iterator insert(iterator target_pos, InputIterator begin, InputIterator end, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type dum = 0)
        {
            dum = 0;
            unsigned int i = 0;
            T* t_pos_ptr = target_pos.getptr();

            for (InputIterator tmp; tmp != end; tmp++)
                i++;
            
            vec_pusher(t_pos_ptr, i);

            // @if_error@ 혹시 삽입에 1정도 길이 차이가 나면 이 부분을 고쳐보쟈 
            i = -1;
            for (InputIterator iter; iter != end; iter++)
            {
                ++i;
                set_value(target_pos + i, *iter);
            }
            elem_num += i;
        }
    }

}



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