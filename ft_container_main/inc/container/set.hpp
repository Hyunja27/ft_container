#ifndef SET_HPP
# define SET_HPP

#include <iostream>
#include <memory>
#include "../pair.hpp"
#include "../iterator/map_iterator.hpp"

namespace ft
{
    template <class T, class Compare = less<T>, class Alloc = std::allocator<T> >
    class set
    {

        public:
            typedef T                                        key_type;
            typedef T                                        value_type;
            typedef Compare                                  key_compare;
            typedef Alloc                                    allocator_type;
            typedef size_t                                   size_type;
            typedef typename allocator_type::reference       reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer         pointer;
            typedef typename allocator_type::const_pointer   const_pointer;
            typedef typename allocator_type::size_type       size_type;
            typedef typename allocator_type::difference_type difference_type;

            typedef ft::mapIterator< value_type, value_type*, Compare>                 iterator;
            typedef ft::mapIterator< value_type, value_type*, Compare>                 const_iterator;
            typedef ft::mapReverseIterator< value_type, value_type*, Compare>          reverse_iterator;
            typedef ft::mapReverseConstIterator< value_type, value_type*, Compare>     const_reverse_iterator;
            typedef ft::node< value_type, value_type*, Compare>                        tree;
    
        private:
            unsigned int                    elem_num;
            node< value_type, value_type*, Compare> *         root;
            key_compare                                       comp;
            allocator_type                                    allocer;

        //===============================================================================
        //================================= Constructer =================================
        //===============================================================================

        public:
            explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : elem_num(0), root(), comp(comp), allocer(alloc) 
            {
            }

        template < class InputIterator >
        set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(), typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type* = u_nullptr) : elem_num(0), root(), comp(comp), allocer(alloc) 
        {
          insert(first, last);
        }


        set(const set& param) : elem_num(0), root(), comp(param._comp), allocer(param.allocer) 
        { 
            *this = param; 
        }

        virtual ~set() 
        {

        }

        set& operator=(const set& param) 
        {
            if (this != &param) 
                this->root.copy(param.root);
            return (*this);
        }

        //===============================================================================
        //================================== iterator ===================================
        //===============================================================================

        iterator begin() 
        { 
            return (iterator(root->getleftest(root))); 
        }
        const_iterator begin() const 
        {
          return (const_iterator(root->getleftest(root)));
        }

        iterator end() 
        { 
            return (iterator(NULL)); 
        }

        const_iterator end() const 
        { 
            return (const_iterator(NULL)); 
        }

        reverse_iterator rbegin() 
        { 
            return (reverse_iterator(root->getRightest(root))); 
        }

        const_reverse_iterator rbegin() const 
        {
            return (const_reverse_iterator(root->getRightest(root)));
        }

        reverse_iterator rend() 
        { 
            return (reverse_iterator(NULL)); 
        }

        const_reverse_iterator rend() const 
        {
          return (const_reverse_iterator(NULL));
        }

        bool empty() const 
        { 
            return (this->elem_num == 0); 
        }
        
        size_type size() const 
        { 
            return (this->elem_num); 
        }

        size_type max_size() const 
        {
            return (this->allocer.max_size());
        }

        //===============================================================================
        //================================= functions ===================================
        //===============================================================================

        pair< iterator, bool > insert(const value_type& val) 
        {
            ft::pair< node_type*, bool > rt = root.insert(val);
                return (ft::make_pair(iterator(rt.first), rt.second));
        }

  /**
   * position은 hint, 강제 아님.
   * insert 성공시
   * 새로운 element 가리키는 iterator 리턴.
   * insert 실패시
   * val과 동일한 Key값 갖고있는 iterator 리턴.
   */
  iterator insert(iterator position, const value_type& val) {
    ft::pair< node_type*, bool > result = _tree.insert(val, position.base());
    return (iterator(result.first));
  }

  /**
   * [first, last) 구간의 element를 insert.
   * 이때, 기존 Key와 중복되는 element는 추가 X.
   * 중복되지 않는 element만 추가한다.
   */
  template < class InputIterator >
  void insert(InputIterator first, InputIterator last,
              typename ft::enable_if< !ft::is_integral< InputIterator >::value,
                                      InputIterator >::type* = u_nullptr) {
    while (first != last) {
      _tree.insert(*first);
      first++;
    }
  }

  void erase(iterator position) { _tree.erase(position.base()); }

  size_type erase(const key_type& k) {
    return (_tree.erase(_tree.search(value_type(k))));
  }

  void erase(iterator first, iterator last) {
    while (first != last) {
      iterator tmp = first;
      ++first;
      erase(tmp);
    }
  }

  void swap(set& x) {
    if (*this == x) {
      return ;
    }

    unsigned char buf[sizeof(set)];
    memcpy(buf, reinterpret_cast< void* >(&x), sizeof(set));
    memcpy(reinterpret_cast< unsigned char* >(&x),
           reinterpret_cast< void* >(this), sizeof(set));
    memcpy(reinterpret_cast< unsigned char* >(this),
           reinterpret_cast< void* >(buf), sizeof(set));
  }

  void clear() { _tree.clear(); }

  key_compare key_comp() const { return (key_compare()); }
  value_compare value_comp() const { return (value_compare()); }

  iterator find(const key_type& k) {
    return (iterator(_tree.search(value_type(k))));
  }

  const_iterator find(const key_type& k) const {
    return (const_iterator(_tree.search(value_type(k))));
  }

  /* k Key 있으면 1, 없으면 0.
  map은 Key가 unique하기떄문에, 1 또는 0이다. */
  size_type count(const key_type& k) const {
    if (_tree.search(value_type(k))->is_nil()) {
      return 0;
    }
    return 1;
  }

  iterator lower_bound(const key_type& k) {
    return (iterator(_tree.lower_bound(value_type(k))));
  }
  const_iterator lower_bound(const key_type& k) const {
    return (const_iterator(_tree.lower_bound(value_type(k))));
  }
  iterator upper_bound(const key_type& k) {
    return (iterator(_tree.upper_bound(value_type(k))));
  }
  const_iterator upper_bound(const key_type& k) const {
    return (const_iterator(_tree.upper_bound(value_type(k))));
  }

  pair< const_iterator, const_iterator > equal_range(const key_type& k) const {
    return (ft::make_pair(lower_bound(k), upper_bound(k)));
  }
  pair< iterator, iterator > equal_range(const key_type& k) {
    return (ft::make_pair(lower_bound(k), upper_bound(k)));
  }

  allocator_type get_allocator() const { return (allocator_type()); }
    };

};