#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <memory>
#include "../pair.hpp"
#include "../iterator/map_iterator.hpp"

namespace ft
{
    template <class Key, class T, class Compare = less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
    class map
    {
        private:
            unsigned int                    elem_num;
            node<Key, T, Compare> *         root;
            saver<Key, T, Compare> *        save;
            Alloc                           allocer;

            void	saveRoot()
			{
				save->root = this->root;
			}

        public:
            typedef Key                                      key_type;
            typedef T                                        mapped_type;
            typedef pair<const key_type, mapped_type>        value_type;
            typedef Compare                                  key_compare;
            typedef Alloc                                    allocator_type;
            typedef typename allocator_type::reference       reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer         pointer;
            typedef typename allocator_type::const_pointer   const_pointer;
            typedef typename allocator_type::size_type       size_type;
            typedef typename allocator_type::difference_type difference_type;

            typedef ft::mapIterator<Key, T, Compare>                  iterator;
            typedef ft::mapConstIterator<Key, T, Compare>             const_iterator;
            typedef ft::mapReverseIterator<Key, T, Compare>           reverse_iterator;
            typedef ft::mapReverseConstIterator<Key, T, Compare>      const_reverse_iterator;



        //From c plusplus Refer.  pair를 직접비교
			class value_compare
			{
				private :
					Compare comp;
					value_compare (Compare c) : comp(c){}
				public	:
					typedef bool result_type;
  					typedef value_type first_argument_type;
  					typedef value_type second_argument_type;

					value_compare(){}

					value_compare(const value_compare& origin) : comp(origin.comp) {}

					~value_compare(){}

					value_compare& operator=(const value_compare& origin)
					{
						comp = origin.comp;
						return (*this);
					}

					bool operator() (const value_type& x, const value_type& y) const
  					{
    					return comp(x.first, y.first);
					}
			};

        
        //===============================================================================
        //================================= Constructer =================================
        //===============================================================================

        explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : elem_num(0), root(NULL)
        {
            (void)alloc;
            (void)comp;
            save = new saver<Key, T, Compare>();
        }

        template <class inputIterator> 
        map (inputIterator start, inputIterator end, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : elem_num(0), root(NULL)
        {
            (void)alloc;
            (void)comp;
            save = new saver<Key, T, Compare>();
            insert(start, end);
        }

        map (const map& param) : elem_num(0), root(NULL)
        {
            // std::cout << "Bye ! " << param.root->set.first << " : " << param.root->set.second << std::endl;
            this->root = new node<Key, T, Compare>(* param.root);
            this->elem_num = param.elem_num;
            save = new saver<Key, T, Compare>();
            saveRoot();
        }

        ~map()
        {
            if (elem_num > 0)
                this->root->deleteTree(this->root);
            delete(save);
        }

        map<Key, T, Compare, Alloc> &operator=(const map& _target)
        {
            if (this != &_target) 
            {
                this->root->deleteTree(this->root);
                this->root = new node<Key, T, Compare>(* _target.root);
                this->elem_num = _target.elem_num;
                saveRoot();
            }
            return (*this);
        }


        //===============================================================================
        //================================== elements ===================================
        //===============================================================================

        mapped_type& operator[]( const key_type& key )
        {
            if (elem_num == 0)
            {
                elem_num++;
                this->root = new node<Key, T, Compare>(key);
                root->color = BLACK;
                root = root->getRoot(root);
                saveRoot();
                return (this->root->set.second);
            }
            else
            {
                node<Key, T, Compare> *tmp;

                tmp = root->find(this->root, key);
                if (tmp != NULL)
                    return (tmp->set.second);
                else
                {
                    node<Key, T, Compare>* tmp;
                    elem_num++;
                    tmp = (root->insert(this->root, key));
                    root = root->getRoot(root);
                    saveRoot();
                    return tmp->set.second;
                }
            }
        }


        //===============================================================================
        //================================== iterator ===================================
        //===============================================================================

        iterator begin()
        {
            return (iterator(root->getleftest(root), save));
        }

        const_iterator begin() const
        {
            return (const_iterator(root->getleftest(root), save));
        }

        iterator end()
        {
            return (iterator(NULL, save));
        }

        const_iterator end() const
        {
            return (const_iterator(NULL, save));
        }

        reverse_iterator rbegin()
        {
            return (reverse_iterator(root->getRightest(root), save));
        }

        const_reverse_iterator rbegin() const
        {
            return (const_reverse_iterator(root->getRightest(root), save));
        }

        reverse_iterator rend()
        {
            return (reverse_iterator(NULL, save));
        }

        const_reverse_iterator rend() const
        {
            return (const_reverse_iterator(NULL, save));
        }

        //===============================================================================
        //================================== capacity ===================================
        //===============================================================================

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

        void clear()
        {
            if (elem_num == 0)
                return ;
            elem_num = 0;
            root->deleteTree(root);
            root = NULL;
        }

        pair<iterator, bool> insert( const value_type& value )
        {
            if (elem_num == 0)
            {
                elem_num++;
                this->root = new node<Key, T, Compare>(value.first, value.second);
                root = root->getRoot(root);
                saveRoot();
                return(pair<iterator, bool>(iterator(root, save), true));
            }
            else
            {
                node<Key, T, Compare> *tmp;

                tmp = root->find(this->root, value.first);
                if (tmp != NULL)
                    return(pair<iterator, bool>(iterator(tmp, save), false));
                else
                {
                    elem_num++;
                    tmp = root->insert(root, value.first, value.second);
                    root = root->getRoot(root);
                    saveRoot();
                    return(pair<iterator, bool>(iterator(tmp, save), true));
                }
            }
        }

        iterator insert( iterator hint, const value_type& value )
        {
            (void)hint;
            return (insert(value).first);
        }

        template< class Inputiterator >
        void insert( Inputiterator first, Inputiterator last )
        {
            for (Inputiterator it = first; it != last; it++)
                insert(pair<const Key, T>(it->first, it->second));
        }

        size_type erase(const key_type& param)
        {
            if (elem_num == 0)
                return (0);
            else
            {
                // std::cout << "param : " << param << std::endl;
                if (root->find(root, param) != NULL)
                {
                    // node<Key, T, Compare>* tmp = root->getRightest(root);
                    // if (tmp == NULL)
                    //     tmp = root->getleftest(root);
                    std::cout << "before erase root : " << root->set.first << std::endl;
                    std::cout << "erase key : " << param << std::endl;


                    root->deleteNode(this->root, param);


                    // root = root->getRoot(root);

                    std::cout << "after erase root : " << root->set.first << std::endl;
                    
                    // std::cout << "root " << root << std::endl;
                    // std::cout << "tmp : " << tmp << std::endl;

                    elem_num--;
                    if (elem_num == 0)
                    {
                        root = NULL;
                        saveRoot();
                    }
                    // else if (tmp != NULL)
                    // {
                    //     // /////??????????????
                    //     // while ((tmp->getParent(tmp) && (tmp != tmp->getParent(tmp))))
                    //     // {
                    //     //     tmp = tmp->getParent(tmp);
                    //     // }
                    //     // // std::cout << "?????" << std::endl;
                    //     // tmp = root->getRoot(tmp);

                    //     // while (tmp->parent != NULL)
                    //     //     tmp = tmp->parent;
                    //     // root = tmp;

                    //     saveRoot();
                    // }
                    saveRoot();
                    return (1);
                }
                else
                    return (0);
            }
        }

        void erase(iterator pos)
        {
            erase(pos->first);
        }

        void erase( iterator first, iterator last )
        {

            iterator tmp_1 = first;
            iterator tmp_2;
            while(tmp_1 != last)
            {
                tmp_2 = tmp_1;
                tmp_2++;
                // std::cout << "erase : " << tmp_1.getPtr()->set.first << std::endl;
                erase(tmp_1);
                tmp_1 = tmp_2;
                if (tmp_1 == last)
                    break ;
            }
        }

        void swap( map& other )
        {
            node<Key, T, Compare> *tmp = root;
            size_t tmp_int = this->elem_num;

            root = other.root;
            other.root = tmp;

            elem_num = other.elem_num;
            other.elem_num = tmp_int;

        }

        size_type count( const key_type& param ) const
        {
            if (elem_num == 0)
                return (0);
            else
            {
                if (root->find(root, param) != NULL)
                    return (1);
                else
                    return (0);
            }
        }

        iterator find( const key_type& param )
        {
            if (elem_num == 0)
                return (iterator(NULL, save));
            else
                return (iterator(root->find(root, param), save));
        }

        const_iterator find( const key_type& param ) const
        {
            if (elem_num == 0)
                return (const_iterator(NULL, save));
            else
                return (const_iterator(root->find(root, param), save));
        }

        pair<iterator,iterator> equal_range( const key_type& param )
        {
            return (pair<iterator, iterator>(lower_bound(param), upper_bound(param)));
        }

        pair<const_iterator,const_iterator> equal_range( const key_type& param ) const
        {
            return (pair<const_iterator, const_iterator>(lower_bound(param), upper_bound(param)));
        }

        iterator lower_bound( const key_type& param )
        {
            if (elem_num == 0)
                return (iterator(NULL, save));
            else
                return (iterator(root->getLowerBound(root, param), save));
        }

        const_iterator lower_bound( const key_type& param ) const
        {
            if (elem_num == 0)
                return (const_iterator(NULL, save));
            else
                return (const_iterator(root->getLowerBound(root, param), save));
        }

        iterator upper_bound( const key_type& param )
        {
            if (elem_num == 0)
                return (iterator(NULL, save));
            else
                return (iterator(root->getUpperBound(root, param), save));
        }

        const_iterator upper_bound( const key_type& param ) const
        {
            if (elem_num == 0)
                return (const_iterator(NULL, save));
            else
                return (const_iterator(root->getUpperBound(root, param), save));
        }

        key_compare key_comp() const
        {
            return (Compare());
        }
        
        value_compare value_comp() const
        {
            return (value_compare());
        }
    };
}

#endif


/*

    this is real map synop.

    map synopsis

namespace std
{

template <class Key, class T, class Compare = less<Key>,
          class Allocator = allocator<pair<const Key, T>>>
class map
{
public:
    // types:
    typedef Key                                      key_type;
    typedef T                                        mapped_type;
    typedef pair<const key_type, mapped_type>        value_type;
    typedef Compare                                  key_compare;
    typedef Allocator                                allocator_type;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;
    typedef typename allocator_type::size_type       size_type;
    typedef typename allocator_type::difference_type difference_type;

    typedef implementation-defined                   iterator;
    typedef implementation-defined                   const_iterator;
    typedef std::reverse_iterator<iterator>          reverse_iterator;
    typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;
    typedef unspecified                              node_type;              // C++17
    typedef INSERT_RETURN_TYPE<iterator, node_type>  insert_return_type;     // C++17

    class value_compare
        : public binary_function<value_type, value_type, bool>
    {
        friend class map;
    protected:
        key_compare comp;

        value_compare(key_compare c);
    public:
        bool operator()(const value_type& x, const value_type& y) const;
    };

    // construct/copy/destroy:
    map()
        noexcept(
            is_nothrow_default_constructible<allocator_type>::value &&
            is_nothrow_default_constructible<key_compare>::value &&
            is_nothrow_copy_constructible<key_compare>::value);
    explicit map(const key_compare& comp);
    map(const key_compare& comp, const allocator_type& a);
    template <class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare& comp = key_compare());
    template <class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare& comp, const allocator_type& a);
    map(const map& m);
    map(map&& m)
        noexcept(
            is_nothrow_move_constructible<allocator_type>::value &&
            is_nothrow_move_constructible<key_compare>::value);
    explicit map(const allocator_type& a);
    map(const map& m, const allocator_type& a);
    map(map&& m, const allocator_type& a);
    map(initializer_list<value_type> il, const key_compare& comp = key_compare());
    map(initializer_list<value_type> il, const key_compare& comp, const allocator_type& a);
    template <class InputIterator>
        map(InputIterator first, InputIterator last, const allocator_type& a)
            : map(first, last, Compare(), a) {}  // C++14
    map(initializer_list<value_type> il, const allocator_type& a)
        : map(il, Compare(), a) {}  // C++14
   ~map();

    map& operator=(const map& m);
    map& operator=(map&& m)
        noexcept(
            allocator_type::propagate_on_container_move_assignment::value &&
            is_nothrow_move_assignable<allocator_type>::value &&
            is_nothrow_move_assignable<key_compare>::value);
    map& operator=(initializer_list<value_type> il);

    // iterators:
          iterator begin() noexcept;
    const_iterator begin() const noexcept;
          iterator end() noexcept;
    const_iterator end()   const noexcept;

          reverse_iterator rbegin() noexcept;
    const_reverse_iterator rbegin() const noexcept;
          reverse_iterator rend() noexcept;
    const_reverse_iterator rend()   const noexcept;

    const_iterator         cbegin()  const noexcept;
    const_iterator         cend()    const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend()   const noexcept;

    // capacity:
    bool      empty()    const noexcept;
    size_type size()     const noexcept;
    size_type max_size() const noexcept;

    // element access:
    mapped_type& operator[](const key_type& k);
    mapped_type& operator[](key_type&& k);

          mapped_type& at(const key_type& k);
    const mapped_type& at(const key_type& k) const;

    // modifiers:
    template <class... Args>
        pair<iterator, bool> emplace(Args&&... args);
    template <class... Args>
        iterator emplace_hint(const_iterator position, Args&&... args);
    pair<iterator, bool> insert(const value_type& v);
    pair<iterator, bool> insert(      value_type&& v);                                // C++17
    template <class P>
        pair<iterator, bool> insert(P&& p);
    iterator insert(const_iterator position, const value_type& v);
    iterator insert(const_iterator position,       value_type&& v);                   // C++17
    template <class P>
        iterator insert(const_iterator position, P&& p);
    template <class InputIterator>
        void insert(InputIterator first, InputIterator last);
    void insert(initializer_list<value_type> il);

    node_type extract(const_iterator position);                                       // C++17
    node_type extract(const key_type& x);                                             // C++17
    insert_return_type insert(node_type&& nh);                                        // C++17
    iterator insert(const_iterator hint, node_type&& nh);                             // C++17

    template <class... Args>
        pair<iterator, bool> try_emplace(const key_type& k, Args&&... args);          // C++17
    template <class... Args>
        pair<iterator, bool> try_emplace(key_type&& k, Args&&... args);               // C++17
    template <class... Args>
        iterator try_emplace(const_iterator hint, const key_type& k, Args&&... args); // C++17
    template <class... Args>
        iterator try_emplace(const_iterator hint, key_type&& k, Args&&... args);      // C++17
    template <class M>
        pair<iterator, bool> insert_or_assign(const key_type& k, M&& obj);            // C++17
    template <class M>
        pair<iterator, bool> insert_or_assign(key_type&& k, M&& obj);                 // C++17
    template <class M>
        iterator insert_or_assign(const_iterator hint, const key_type& k, M&& obj);   // C++17
    template <class M>
        iterator insert_or_assign(const_iterator hint, key_type&& k, M&& obj);        // C++17

    iterator  erase(const_iterator position);
    iterator  erase(iterator position); // C++14
    size_type erase(const key_type& k);
    iterator  erase(const_iterator first, const_iterator last);
    void clear() noexcept;

    template<class C2>
      void merge(map<Key, T, C2, Allocator>& source);         // C++17
    template<class C2>
      void merge(map<Key, T, C2, Allocator>&& source);        // C++17
    template<class C2>
      void merge(multimap<Key, T, C2, Allocator>& source);    // C++17
    template<class C2>
      void merge(multimap<Key, T, C2, Allocator>&& source);   // C++17

    void swap(map& m)
        noexcept(allocator_traits<allocator_type>::is_always_equal::value &&
            is_nothrow_swappable<key_compare>::value); // C++17

    // observers:
    allocator_type get_allocator() const noexcept;
    key_compare    key_comp()      const;
    value_compare  value_comp()    const;

    // map operations:
          iterator find(const key_type& k);
    const_iterator find(const key_type& k) const;
    template<typename K>
        iterator find(const K& x);              // C++14
    template<typename K>
        const_iterator find(const K& x) const;  // C++14
    template<typename K>
      size_type count(const K& x) const;        // C++14
    size_type      count(const key_type& k) const;
        bool contains(const key_type& x) const; // C++20
          iterator lower_bound(const key_type& k);
    const_iterator lower_bound(const key_type& k) const;
    template<typename K>
        iterator lower_bound(const K& x);              // C++14
    template<typename K>
        const_iterator lower_bound(const K& x) const;  // C++14

          iterator upper_bound(const key_type& k);
    const_iterator upper_bound(const key_type& k) const;
    template<typename K>
        iterator upper_bound(const K& x);              // C++14
    template<typename K>
        const_iterator upper_bound(const K& x) const;  // C++14

    pair<iterator,iterator>             equal_range(const key_type& k);
    pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
    template<typename K>
        pair<iterator,iterator>             equal_range(const K& x);        // C++14
    template<typename K>
        pair<const_iterator,const_iterator> equal_range(const K& x) const;  // C++14
};

template <class Key, class T, class Compare, class Allocator>
bool
operator==(const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y);

template <class Key, class T, class Compare, class Allocator>
bool
operator< (const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y);

template <class Key, class T, class Compare, class Allocator>
bool
operator!=(const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y);

template <class Key, class T, class Compare, class Allocator>
bool
operator> (const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y);

template <class Key, class T, class Compare, class Allocator>
bool
operator>=(const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y);

template <class Key, class T, class Compare, class Allocator>
bool
operator<=(const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y);

// specialized algorithms:
template <class Key, class T, class Compare, class Allocator>
void
swap(map<Key, T, Compare, Allocator>& x, map<Key, T, Compare, Allocator>& y)
    noexcept(noexcept(x.swap(y)));

template <class Key, class T, class Compare, class Allocator, class Predicate>
typename map<Key, T, Compare, Allocator>::size_type
erase_if(map<Key, T, Compare, Allocator>& c, Predicate pred);  // C++20


template <class Key, class T, class Compare = less<Key>,
          class Allocator = allocator<pair<const Key, T>>>
class multimap
{
public:
    // types:
    typedef Key                                      key_type;
    typedef T                                        mapped_type;
    typedef pair<const key_type,mapped_type>         value_type;
    typedef Compare                                  key_compare;
    typedef Allocator                                allocator_type;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::size_type       size_type;
    typedef typename allocator_type::difference_type difference_type;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;

    typedef implementation-defined                   iterator;
    typedef implementation-defined                   const_iterator;
    typedef std::reverse_iterator<iterator>          reverse_iterator;
    typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;
    typedef unspecified                              node_type;              // C++17

    class value_compare
        : public binary_function<value_type,value_type,bool>
    {
        friend class multimap;
    protected:
        key_compare comp;
        value_compare(key_compare c);
    public:
        bool operator()(const value_type& x, const value_type& y) const;
    };

    // construct/copy/destroy:
    multimap()
        noexcept(
            is_nothrow_default_constructible<allocator_type>::value &&
            is_nothrow_default_constructible<key_compare>::value &&
            is_nothrow_copy_constructible<key_compare>::value);
    explicit multimap(const key_compare& comp);
    multimap(const key_compare& comp, const allocator_type& a);
    template <class InputIterator>
        multimap(InputIterator first, InputIterator last, const key_compare& comp);
    template <class InputIterator>
        multimap(InputIterator first, InputIterator last, const key_compare& comp,
                 const allocator_type& a);
    multimap(const multimap& m);
    multimap(multimap&& m)
        noexcept(
            is_nothrow_move_constructible<allocator_type>::value &&
            is_nothrow_move_constructible<key_compare>::value);
    explicit multimap(const allocator_type& a);
    multimap(const multimap& m, const allocator_type& a);
    multimap(multimap&& m, const allocator_type& a);
    multimap(initializer_list<value_type> il, const key_compare& comp = key_compare());
    multimap(initializer_list<value_type> il, const key_compare& comp,
             const allocator_type& a);
    template <class InputIterator>
        multimap(InputIterator first, InputIterator last, const allocator_type& a)
            : multimap(first, last, Compare(), a) {} // C++14
    multimap(initializer_list<value_type> il, const allocator_type& a)
        : multimap(il, Compare(), a) {} // C++14
    ~multimap();

    multimap& operator=(const multimap& m);
    multimap& operator=(multimap&& m)
        noexcept(
            allocator_type::propagate_on_container_move_assignment::value &&
            is_nothrow_move_assignable<allocator_type>::value &&
            is_nothrow_move_assignable<key_compare>::value);
    multimap& operator=(initializer_list<value_type> il);

    // iterators:
          iterator begin() noexcept;
    const_iterator begin() const noexcept;
          iterator end() noexcept;
    const_iterator end()   const noexcept;

          reverse_iterator rbegin() noexcept;
    const_reverse_iterator rbegin() const noexcept;
          reverse_iterator rend() noexcept;
    const_reverse_iterator rend()   const noexcept;

    const_iterator         cbegin()  const noexcept;
    const_iterator         cend()    const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend()   const noexcept;

    // capacity:
    bool      empty()    const noexcept;
    size_type size()     const noexcept;
    size_type max_size() const noexcept;

    // modifiers:
    template <class... Args>
        iterator emplace(Args&&... args);
    template <class... Args>
        iterator emplace_hint(const_iterator position, Args&&... args);
    iterator insert(const value_type& v);
    iterator insert(      value_type&& v);                                            // C++17
    template <class P>
        iterator insert(P&& p);
    iterator insert(const_iterator position, const value_type& v);
    iterator insert(const_iterator position,       value_type&& v);                   // C++17
    template <class P>
        iterator insert(const_iterator position, P&& p);
    template <class InputIterator>
        void insert(InputIterator first, InputIterator last);
    void insert(initializer_list<value_type> il);

    node_type extract(const_iterator position);                                       // C++17
    node_type extract(const key_type& x);                                             // C++17
    iterator insert(node_type&& nh);                                                  // C++17
    iterator insert(const_iterator hint, node_type&& nh);                             // C++17

    iterator  erase(const_iterator position);
    iterator  erase(iterator position); // C++14
    size_type erase(const key_type& k);
    iterator  erase(const_iterator first, const_iterator last);
    void clear() noexcept;

    template<class C2>
      void merge(multimap<Key, T, C2, Allocator>& source);    // C++17
    template<class C2>
      void merge(multimap<Key, T, C2, Allocator>&& source);   // C++17
    template<class C2>
      void merge(map<Key, T, C2, Allocator>& source);         // C++17
    template<class C2>
      void merge(map<Key, T, C2, Allocator>&& source);        // C++17

    void swap(multimap& m)
        noexcept(allocator_traits<allocator_type>::is_always_equal::value &&
            is_nothrow_swappable<key_compare>::value); // C++17

    // observers:
    allocator_type get_allocator() const noexcept;
    key_compare    key_comp()      const;
    value_compare  value_comp()    const;

    // map operations:
          iterator find(const key_type& k);
    const_iterator find(const key_type& k) const;
    template<typename K>
        iterator find(const K& x);              // C++14
    template<typename K>
        const_iterator find(const K& x) const;  // C++14
    template<typename K>
      size_type count(const K& x) const;        // C++14
    size_type      count(const key_type& k) const;
        bool contains(const key_type& x) const; // C++20
          iterator lower_bound(const key_type& k);
    const_iterator lower_bound(const key_type& k) const;
    template<typename K>
        iterator lower_bound(const K& x);              // C++14
    template<typename K>
        const_iterator lower_bound(const K& x) const;  // C++14

          iterator upper_bound(const key_type& k);
    const_iterator upper_bound(const key_type& k) const;
    template<typename K>
        iterator upper_bound(const K& x);              // C++14
    template<typename K>
        const_iterator upper_bound(const K& x) const;  // C++14

    pair<iterator,iterator>             equal_range(const key_type& k);
    pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
    template<typename K>
        pair<iterator,iterator>             equal_range(const K& x);        // C++14
    template<typename K>
        pair<const_iterator,const_iterator> equal_range(const K& x) const;  // C++14
};

template <class Key, class T, class Compare, class Allocator>
bool
operator==(const multimap<Key, T, Compare, Allocator>& x,
           const multimap<Key, T, Compare, Allocator>& y);

template <class Key, class T, class Compare, class Allocator>
bool
operator< (const multimap<Key, T, Compare, Allocator>& x,
           const multimap<Key, T, Compare, Allocator>& y);

template <class Key, class T, class Compare, class Allocator>
bool
operator!=(const multimap<Key, T, Compare, Allocator>& x,
           const multimap<Key, T, Compare, Allocator>& y);

template <class Key, class T, class Compare, class Allocator>
bool
operator> (const multimap<Key, T, Compare, Allocator>& x,
           const multimap<Key, T, Compare, Allocator>& y);

template <class Key, class T, class Compare, class Allocator>
bool
operator>=(const multimap<Key, T, Compare, Allocator>& x,
           const multimap<Key, T, Compare, Allocator>& y);

template <class Key, class T, class Compare, class Allocator>
bool
operator<=(const multimap<Key, T, Compare, Allocator>& x,
           const multimap<Key, T, Compare, Allocator>& y);

// specialized algorithms:
template <class Key, class T, class Compare, class Allocator>
void
swap(multimap<Key, T, Compare, Allocator>& x,
     multimap<Key, T, Compare, Allocator>& y)
    noexcept(noexcept(x.swap(y)));

template <class Key, class T, class Compare, class Allocator, class Predicate>
typename multimap<Key, T, Compare, Allocator>::size_type
erase_if(multimap<Key, T, Compare, Allocator>& c, Predicate pred);  // C++20

}  // std

*/