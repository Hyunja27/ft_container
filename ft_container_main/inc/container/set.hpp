#ifndef SET_HPP
# define SET_HPP

#include <iostream>
#include <memory>
#include "../pair.hpp"
#include "../iterator/set_iterator.hpp"


namespace ft
{
    template <class Key, class Compare = less<Key>, class Alloc = std::allocator<pair<const Key, Key> > >
    class set
    {
        private:
            unsigned int                    elem_num;
            node<Key, Key, Compare> *         root;
            saver<Key, Key, Compare> *        save;
            Alloc                           allocer;

            void	saveRoot()
			{
				save->root = this->root;
			}

        public:
            typedef Key                                      key_type;
            typedef Key                                      mapped_type;
            typedef pair<const key_type, mapped_type>        value_type;
            typedef Compare                                  key_compare;
            typedef key_compare                              value_compare;
            typedef Alloc                                    allocator_type;
            typedef typename allocator_type::reference       reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer         pointer;
            typedef typename allocator_type::const_pointer   const_pointer;
            typedef typename allocator_type::size_type       size_type;
            typedef typename allocator_type::difference_type difference_type;

            typedef ft::setIterator<Key, Key, Compare>                  iterator;
            typedef ft::setConstIterator<Key, Key, Compare>             const_iterator;
            typedef ft::setReverseIterator<Key, Key, Compare>           reverse_iterator;
            typedef ft::setReverseConstIterator<Key, Key, Compare>      const_reverse_iterator;

        
        //===============================================================================
        //================================= Constructer =================================
        //===============================================================================

        explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : elem_num(0), root(NULL)
        {
            (void)alloc;
            (void)comp;
            save = new saver<Key, Key, Compare>();
        }

        template <class inputIterator> 
        set (inputIterator start, inputIterator end, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : elem_num(0), root(NULL)
        {
            (void)alloc;
            (void)comp;
            save = new saver<Key, Key, Compare>();
            insert(start, end);
        }

        set (const set& param) : elem_num(0), root(NULL)
        {
            // std::cout << "Bye ! " << param.root->set.first << " : " << param.root->set.second << std::endl;
            this->root = new node<Key, Key, Compare>(* param.root);
            this->elem_num = param.elem_num;
            save = new saver<Key, Key, Compare>();
            saveRoot();
        }

        ~set()
        {
            if (elem_num > 0)
                this->root->deleteTree(this->root);
            delete(save);
        }

        set<Key, Compare, Alloc> &operator=(const set& _target)
        {
            if (this != &_target) 
            {
                this->root->deleteTree(this->root);
                this->root = new node<Key, Key, Compare>(* _target.root);
                this->elem_num = _target.elem_num;
                saveRoot();
            }
            return (*this);
        }


        //===============================================================================
        //================================== elements ===================================
        //===============================================================================

        // mapped_type& operator[]( const key_type& key )
        // {
        //     if (elem_num == 0)
        //     {
        //         elem_num++;
        //         this->root = new node<Key, Key, Compare>(key);
        //         root->color = BLACK;
        //         root = root->getRoot(root);
        //         saveRoot();
        //         return (this->root->set.second);
        //     }
        //     else
        //     {
        //         node<Key, Key, Compare> *tmp;

        //         tmp = root->find(this->root, key);
        //         if (tmp != NULL)
        //             return (tmp->set.second);
        //         else
        //         {
        //             node<Key, Key, Compare>* tmp;
        //             elem_num++;
        //             tmp = (root->insert(this->root, key));
        //             root = root->getRoot(root);
        //             saveRoot();
        //             return tmp->set.second;
        //         }
        //     }
        // }


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

        node<Key, Key, Compare> *		getRoot()
		{
			return (this->root);
		}

        void clear()
        {
            if (elem_num == 0)
                return ;
            elem_num = 0;
            root->deleteTree(root);
            root = NULL;
        }

        pair<iterator, bool> insert( const key_type& value )
        {
            if (elem_num == 0)
            {
                elem_num++;
                this->root = new node<Key, Key, Compare>(value, value);
                root = root->getRoot(root);
                saveRoot();
                return(pair<iterator, bool>(iterator(root, save), true));
            }
            else
            {
                node<Key, Key, Compare> *tmp;

                tmp = root->find(this->root, value);
                if (tmp != NULL)
                    return(pair<iterator, bool>(iterator(tmp, save), false));
                else
                {
                    elem_num++;
                    tmp = root->insert(root, value, value);
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
                insert(*it);
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
                    // std::cout << "before erase root : " << root->set.first << std::endl;
                    // std::cout << "erase key : " << param << std::endl;
                    
                    root->deleteNode(this->root, param);

                    // std::cout << "after root pointer: " << root << std::endl;


                    // root = root->getRoot(root);

                    // std::cout << "after erase root : " << root->set.first << std::endl;
                    
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
            erase(*pos);
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

        void swap( set& other )
        {
            node<Key, Key, Compare> *tmp = root;
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

    template <class Key, class Compare, class Alloc>
    bool operator==(const set< Key, Compare, Alloc>& lhs, const set< Key, Compare, Alloc>& rhs) 
    {
      return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template < class Key, class Compare, class Alloc >
    bool operator!=(const set< Key, Compare, Alloc>& lhs, const set< Key, Compare, Alloc>& rhs) 
    {
      return (!(lhs == rhs));
    }

    template < class Key, class Compare, class Alloc >
    bool operator<(const set< Key, Compare, Alloc>& lhs, const set< Key, Compare, Alloc>& rhs) 
    {
      return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template < class Key, class Compare, class Alloc >
    bool operator<=(const set< Key, Compare, Alloc>& lhs, const set< Key, Compare, Alloc>& rhs) 
    {
      return (!(rhs < lhs));
    }

    template < class Key, class Compare, class Alloc >
    bool operator>(const set< Key, Compare, Alloc>& lhs, const set< Key, Compare, Alloc>& rhs) 
    {
      return (rhs < lhs);
    }

    template < class Key, class Compare, class Alloc >
    bool operator>=(const set< Key, Compare, Alloc>& lhs, const set< Key, Compare, Alloc>& rhs) 
    {
      return (!(lhs < rhs));
    }
}

#endif