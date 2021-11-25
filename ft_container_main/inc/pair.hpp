#ifndef PAIR_HPP
#define PAIR_HPP

#define RED     false
#define BLACK   true

#include "./tools.hpp"
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

            pair &operator=(const pair &target)
            {
                this->first = target.first;
                this->second = target.second;
                return (*this);
            }

            ~pair() {}

            //===============================================================================
            //================================= functions ===================================
            //===============================================================================
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


    template<class Key, class Val, class Compare = ft::less<Key> >
    class node
    {

        //===============================================================================
        //=============================== Private & public ==============================
        //===============================================================================

        private:
            // false: red, true: black, 2: Unknown
            Compare cmp;

        public:
            node    *left;
            node    *right;
            node    *parent;
            bool     color;
            pair<const Key, Val> set;

        //===============================================================================
        //================================= Constructer =================================
        //===============================================================================
        
        node() : left(NULL), right(NULL), parent(NULL), color(false), set(NULL)
        {
            
        }

        node(Key first, Val second = Val()) : left(NULL), right(NULL), parent(NULL),  set(first, second)
		{

        }

        node(const pair<Key, Val> _set) : left(NULL), right(NULL), parent(NULL), color(false)
        {
            this->set = _set;
        }

        node(const node<Key, Val, Compare>& origin, node<Key, Val, Compare>* parent = NULL) : left(NULL), right(NULL), parent(parent), set(origin.set)
			{
				if (origin.left != NULL)
					left = new node<Key, Val, Compare>(*origin.left, this);
				if (origin.right != NULL)
					right = new node<Key, Val, Compare>(*origin.right, this);				
			}

        ~node()
        {

        }

        node<Key, Val, Compare>& operator=(const node<Key, Val, Compare>& origin)
		{
			delete (parent);
			parent = new node<Key, Val, Compare>(origin.parent);
			delete (left);
			left = new node<Key, Val, Compare>(origin.left);
			delete (right);
			right = new node<Key, Val, Compare>(origin.right);
			
            set = origin.set;
			
            return (*this);
		}

        //===============================================================================
        //================================= functions ===================================
        //===============================================================================
 
        void childChange(node *from, node *to)
		{
			if (left == from)
				left = to;
			if (right == from)
				right = to;
		}

		void makeParentChildToMyChild()
		{
			if (parent == NULL)
				return ;
			if (left == NULL)
				parent->childChange(this, right);
			else
				parent->childChange(this, left);
		}

        node<Key, Val, Compare>* getRoot(node<Key, Val, Compare>* base)
        {
            // std::cout << " getRoot -> base : " << base << std::endl;
            if (base == NULL)
                return NULL;
            if (base->parent == NULL)
            {
                return (base);
            }
            return (getRoot(base->parent));
        }

        node<Key, Val, Compare>* getRight(node<Key, Val, Compare>* base)
        {
            // if (base->right == NULL)
            // {
            //     throw std::out_of_range("No Right Node!");
            // }
            return (base->right);
        }

        node<Key, Val, Compare>* getLeft(node<Key, Val, Compare>* base)
        {
            // if (base->left == NULL)
            // {
            //     throw std::out_of_range("No Right Node!");
            // }
            return (base->left);
        }

        node<Key, Val, Compare>* getParent(node<Key, Val, Compare>* base)
        {
            // if (base->left == NULL)
            // {
            //     throw std::out_of_range("No Right Node!");
            // }
            return (base->parent);
        }

        node<Key, Val, Compare>* getRightest(node<Key, Val, Compare>* base)
        {
            if (base == NULL || base->right == NULL)
                return (base);
            return (getRightest(base->right));
        }

        node<Key, Val, Compare>* getleftest(node<Key, Val, Compare>* base)
        {
            if (base == NULL || base->left == NULL)
                return (base);
            return (getleftest(base->left));
        }

        node<Key, Val, Compare>* find(node<Key, Val, Compare>* base, const Key& target_key)
        {
            if (base == NULL)
                return (NULL);
            if (((base->set.first < target_key) == false) && ((target_key < base->set.first) == false))
                return (base);
            if (this->cmp(target_key, base->set.first))
            {
                if (base->left == NULL)
                    return NULL;
                return (find(base->left, target_key));
            }
            else
            {
                if (base->right == NULL)
                    return NULL;
                return (find(base->right, target_key));
            }
        }

        node<Key, Val, Compare>* insert(node<Key, Val, Compare>* base, const Key& target_key, const Val& target_val = Val())
        {
            node<Key, Val, Compare>* tmp;

            if (target_key < base->set.first)
            {
                if (base->left == NULL)
                {
                    tmp = new node<Key, Val, Compare>(target_key, target_val);
                    base->left = tmp;
                    tmp->color = RED;
                    tmp->right = NULL;
                    tmp->left = NULL;
                    tmp->parent = base;
                    logic_checker(tmp, base);
                    return tmp;
                }
                else
                    return insert(base->left, target_key, target_val);
            }
            else
            {
                if (base->right == NULL)
                {
                    tmp = new node<Key, Val, Compare>(target_key, target_val);
                    base->right = tmp;
                    tmp->color = RED;
                    tmp->right = NULL;
                    tmp->left = NULL;
                    tmp->parent = base;
                    logic_checker(tmp, base);
                    return tmp;
                }
                else
                    return insert(base->right, target_key, target_val);
            }

        }

        // node<Key, Val, Compare>* insert(node<Key, Val, Compare>* base, const Key& target_key, const Val& target_val = Val())
        // {
        //     node<Key, Val, Compare>* tmp;

        //     if ((cmp(base->set.first, target_key) == false) && (cmp(target_key, base->set.first) == false))
        //     {
        //         base->set.second = target_val;
        //         return (base);
        //     }
        //     if (this->cmp(target_key, base->set.first))
        //     {
        //         if (base->left == NULL)
        //         {
        //             tmp = new node<Key, Val, Compare>(target_key, target_val);
        //             tmp->parent = base;
        //             tmp->left = NULL;
        //             tmp->right = NULL;
        //             tmp->color = 0;
        //             base->left = tmp;
        //             // color_checker(tmp);
        //             return (tmp);
        //         }
        //         return (insert(base->left, target_key, target_val));
        //     }
        //     else
        //     {
        //         if (base->right == NULL)
        //         {
        //             tmp = new node<Key, Val, Compare>(target_key, target_val);
        //             tmp->parent = base;
        //             tmp->left = NULL;
        //             tmp->right = NULL;
        //             tmp->color = 0;
        //             base->right = tmp;
        //             // color_checker(tmp);
        //             return (tmp);
        //         }
        //         return (insert(base->right, target_key, target_val));
        //     }
        // }


        void left_lotate(node<Key, Val, Compare>* target, node<Key, Val, Compare>* real_root)
        {
           node<Key, Val, Compare>* tmp_root;

           if (target->parent == NULL)
           {
               tmp_root = target->right;
               target->right = tmp_root->left;
               if (tmp_root->left != NULL)
                   tmp_root->left->parent = target;

               tmp_root->parent = NULL;        
               tmp_root->left = target;
               target->parent = tmp_root;

               real_root = tmp_root;
           }
           else
           {
               // std::cout << "root's key:" << tree->root->key << std::endl;
               // std::cout << "target's key:" << target->key << std::endl;
               // std::cout << "target's parent's key:" << target->parent->key << std::endl;

               tmp_root = target->right;
               target->right = tmp_root->left;
               if (tmp_root->left != NULL)
                   tmp_root->left->parent = target;
               tmp_root->left = NULL;

               tmp_root->parent = target->parent;
               if ((target->parent->right != NULL) && (target->parent->right == target))
               {
                   target->parent->right = tmp_root;
               }
               else if ((target->parent->left != NULL) && (target->parent->left == target))
                   target->parent->left = tmp_root;

               tmp_root->left = target;
               target->parent = tmp_root;

               real_root = tmp_root;
           }
        }

        void right_lotate(node<Key, Val, Compare>* target, node<Key, Val, Compare>* real_root)
        {
           node<Key, Val, Compare>* tmp_root;

           if (target->parent == NULL)
           {
               tmp_root = target->left;
               target->left = tmp_root->right;
               if (tmp_root->right != NULL)
                   tmp_root->right->parent = target;

               tmp_root->parent = NULL;        
               tmp_root->right = target;
               target->parent = tmp_root;

               real_root = tmp_root;
           }
           else
           {
               tmp_root = target->left;
               target->left = tmp_root->right;
               if (tmp_root->right != NULL)
                   tmp_root->right->parent = target;

               tmp_root->parent = target->parent;
               if ((target->parent->right != NULL) && (target->parent->right == target))
                   target->parent->right = tmp_root;
               else if ((target->parent->left != NULL) && (target->parent->left == target))
                   target->parent->left = tmp_root;

               tmp_root->right = target;
               target->parent = tmp_root;

               real_root = tmp_root;
           }

        }

        void lotater(node<Key, Val, Compare>* target, node<Key, Val, Compare>* real_root)
        {
           node<Key, Val, Compare>* grandparent;

            if (target->parent->parent != NULL)
                grandparent = target->parent->parent;
            else
                return ;
                
           if ((grandparent->right != NULL) && (grandparent->right == target->parent))
           {
               if (target->parent->right == target)
               {
                   target->parent->color = BLACK;
                   grandparent->color = RED;
                   left_lotate(grandparent, real_root);
               }
               else
               {
                   target->color = BLACK;
                   grandparent->color = RED;
                   right_lotate(target->parent, real_root);
                   left_lotate(grandparent, real_root);
               }
           }
           else if ((grandparent->left != NULL) && (grandparent->left == target->parent))
           {
               if (target->parent->left == target)
               {
                   target->parent->color = BLACK;
                   grandparent->color = RED;
                   right_lotate(grandparent, real_root);
               }
               else
               {
                   target->color = BLACK;
                   grandparent->color = RED;
                   left_lotate(target->parent, real_root);
                   right_lotate(grandparent, real_root);
               }
           }
        }

        node<Key, Val, Compare>* uncle_getter(node<Key, Val, Compare>* target)
        {   
            node<Key, Val, Compare>* grandparent;
            
            if (target->parent->parent != NULL)
                grandparent = target->parent->parent;
            else
                return NULL;

            if ((grandparent->left != NULL) && (grandparent->left == target->parent))
                if (grandparent->right == NULL)
                    return NULL;
                else
                    return grandparent->right;
            else if ((grandparent->right != NULL) && (grandparent->right == target->parent))
            {
                if (grandparent->left == NULL)
                    return NULL;
                else
                    return grandparent->left;
            }
            return NULL;
        }

        void logic_checker(node<Key, Val, Compare>* inserted, node<Key, Val, Compare>* real_root)
        {
            if (inserted->parent->color == BLACK)
                return ;
            else
            {
                node<Key, Val, Compare>* uncle = uncle_getter(inserted);
                if (uncle == NULL || uncle->color == BLACK) 
                    lotater(inserted, real_root);
                else
                {
                    inserted->parent->color = BLACK;
                    uncle->color = BLACK;
                    if (inserted->parent->parent->parent == NULL)
                        return ;
                    inserted->parent->parent->color = RED;
                    logic_checker(inserted->parent->parent, real_root);
                }
            }
        }
        
        bool isSame(const Key& k_1, const Key& k_2)
        {
            return (!cmp(k_1, k_2) && !cmp(k_2, k_1));
        }

        bool isFirstSmall(const Key& t1, const Val& t2)
			{
				return (cmp(t1, t2));
			}

		bool isFirstEqualOrSmall(const Key& t1, const Val& t2)
		{
			return (!cmp(t2, t1));
		}

        //key 보다 큰값중 가장 작은 값
		node<Key, Val, Compare>* getUpperBound(node<Key, Val, Compare> *root, const Key& key)
		{		
			if (isFirstEqualOrSmall(root->set.first, key))
			{
				if (root->right == NULL)
				{
                    if ((root->parent != NULL) && root->parent->set.first < root->set.first)    
                        return (NULL);
                    return (root->parent);
                }
				else 
                {
                    // std::cout << "  equalsmall : "<< root->set.first << "  key : " << key << std::endl;
					return (getUpperBound(root->right, key));
                }
			}
			else // key 가 더 작음.
			{
				if (root->left == NULL)
				{
                    // if (root->right != NULL)
                    //     return root->right;
                    return (root);
                }
				else
                {
                    // std::cout << "  big : "<< root->set.first << "  key : " << key << std::endl;
					return (getUpperBound(root->left, key));
                }
			}
		}

		//key 보다 큰값중 가장 작거나 같은 값
		node<Key, Val, Compare>* getLowerBound(node<Key, Val, Compare> *root, const Key& key)
		{
			if (isSame(root->set.first, key)) // 값이 같다면 즉시 리턴
				return (root);
			
			if (isFirstSmall(root->set.first, key))
			{
				if (root->right == NULL)
					return (NULL);
				else 
					return (getLowerBound(root->right, key));
			}
			else // key 가 더 작음.
			{
				if (root->left == NULL)
					return (root);
				else
					return (getLowerBound(root->left, key));
			}
		}

        // !? 사용가능할까 !?
        // void color_checker(node<Key, Val, Compare>* base)
        // {
        //     if ((base->color == 0) && (base->parent == 1))
        //         return ;
        //     else if ((base->color == 0) && (base->parent == 0))
        //     {
        //         if (base->parent->parent->right == base->parent)
        //         {
        //             if (base->parent->parent->left->color == 0)
        //                 // recolor(base);
        //             else if (base->parent->parent->left->color == 1)
        //                 // restructure(base);
        //         }
        //         else if (base->parent->parent->left == base->parent)
        //         {
        //             if (base->parent->parent->right->color == 0)
        //                 // recolor(base);
        //             else if (base->parent->parent->right->color == 1)
        //                 // restructure(base);
        //         }
        //     }
        // }

        void deleteTree(node<Key, Val, Compare>* root)
        {
            if (root == NULL)
                return ;
            if (root->right != NULL)
                deleteTree(root->right);
            if (root->left != NULL)
                deleteTree(root->left);
            delete(root);
        }


        void deleteRestructFivecase(node<Key, Val, Compare>* p, node<Key, Val, Compare>* c, node<Key, Val, Compare>* real_root)
        {
            bool islefted = 0;
            node<Key, Val, Compare>* s = NULL;
            node<Key, Val, Compare>* n_near = NULL;
            node<Key, Val, Compare>* n_far = NULL;

            if (p == NULL)
                return ;
            if (p->left == c)
                islefted = 1;
            else if (p->right == c)
                islefted = 0;
            if (islefted)
            {
                s = p->right;
                n_far = s->right;
                n_near = s->left;
            }
            else
            {
                s = p->left;
                n_far = s->left;
                n_near = s->right;
            }

            if ((p->color == RED) && (s->color == BLACK) && (n_near->color == BLACK) && (n_far->color == BLACK))
            {
                // std::cout << "Case 1 " << std::endl;
                // std::cout << "p : " << p->key << std::endl;
                // std::cout << "c : " << c->key << std::endl;

                p->color = BLACK;
                s->color = RED;
            }
            else if ((s->color == BLACK) && (n_far->color == RED))
            {
                if (islefted)
                {
                    left_lotate(p, real_root);
                    s->color = p->color;
                    p->color = BLACK;
                    n_far->color = BLACK;
                }
                else
                {
                    right_lotate(p, real_root);
                    s->color = p->color;
                    p->color = BLACK;
                    n_far->color = BLACK;
                }
            }
            else if ((s->color == BLACK) && (n_near->color == RED) && (n_far->color == BLACK))
            {
                if (islefted)
                {
                    right_lotate(s, real_root);
                    s->color = RED;
                    n_near->color = BLACK;
                    deleteRestructFivecase(p, c, real_root);
                }
                else
                {
                    left_lotate(s, real_root);
                    s->color = RED;
                    n_near->color = BLACK;
                    deleteRestructFivecase(p, c, real_root);
                }
            }
            else if ((p->color == BLACK) && (s->color == BLACK) && (n_near->color == BLACK) && (n_far->color == BLACK))
            {
                s->color = RED;
                deleteRestructFivecase(p->parent, c->parent, real_root);
            }
            else if ((p->color == BLACK) && (s->color == RED) && (n_near->color == BLACK) && (n_far->color == BLACK))
            {
                if (islefted)
                {
                    left_lotate(p, real_root);
                    s->color = BLACK;
                    p->color = RED;
                }
                else
                {
                    left_lotate(p, real_root);
                    s->color = BLACK;
                    p->color = RED;
                }
            }
        }

        void deleteRestruct(node<Key, Val, Compare>* hooim, node<Key, Val, Compare>* h_jasic, bool isLeft, node<Key, Val, Compare>* real_root)
        {
            if (isLeft == 1)
            {
                hooim->parent->right = h_jasic;
                h_jasic->parent = hooim->parent;
            }
            else
            {
                hooim->parent->left = h_jasic;
                h_jasic->parent = hooim->parent;
            }
            if (hooim->color == BLACK)
            {
                // std::cout << "h_jasic : " << h_jasic->key << std::endl;
                // std::cout << "hooim : " << hooim->key << std::endl;

                if (h_jasic->color == RED)
                    h_jasic->color = BLACK;
                else
                {
                    node<Key, Val, Compare>* p = hooim->parent;
                    node<Key, Val, Compare>* c = h_jasic;
                    deleteRestructFivecase(p, c, real_root);
                }
            }
        }

        void deleteNode(node<Key, Val, Compare>* real_root, const Key& target_key)
        {
            node<Key, Val, Compare>* target = find(real_root, target_key);
            node<Key, Val, Compare>* tmp = NULL;
            node<Key, Val, Compare>* nil = new node(0);
            nil->color = BLACK;
            // nil->set.first = 0;
            nil->right = NULL;
            nil->left = NULL;
            nil->parent = NULL;
            // std::cout << std::endl << "deleting : " << target->key << std::endl << std::endl << std::endl;
            if (target->parent == NULL && (target->right == NULL) && (target->left == NULL))
            {
                delete(nil);
                delete(target);
                return ;
            }
            if (target->color == RED)
            {  
            
                if ((target->right == NULL) && (target->left == NULL))
                {
                    if (target->parent->right == target)
                        target->parent->right = NULL;
                    else if (target->parent->left == target)
                        target->parent->left = NULL;
                }
                else if (target->left != NULL)
                {
                    tmp = getRightest(target->left);
                    // std::cout << std::endl << "red_del tmp : " << tmp->key << std::endl << std::endl << std::endl;
                    // std::cout << std::endl << "red_del target : " << target->key << std::endl << std::endl << std::endl;

                    // std::cout << std::endl << "red_del left : " << target->left->key << std::endl << std::endl << std::endl;
                    // std::cout << std::endl << "red_del right : " << target->right->key << std::endl << std::endl << std::endl;
                    // std::cout << std::endl << "red_del left->right : " << target->left->right->key << std::endl << std::endl << std::endl;
                    //!!
                    if ((tmp->left == NULL) && (tmp->right == NULL) && (tmp->color == BLACK))
                        nil->parent = tmp->parent;
                    tmp->right = target->right;
                    target->right->parent = tmp;

                    // tmp->left = target->left;
                    // target->left->parent = tmp;


                    if (tmp->left != NULL)
                        deleteRestruct(tmp, tmp->left, 1, real_root);

                    if (tmp->parent->right == tmp)
                        tmp->parent->right = NULL;
                    else if (tmp->parent->left == tmp)
                        tmp->parent->left = NULL;
                    tmp->parent = target->parent;
                    if (target->parent->right == target)
                        target->parent->right = tmp;
                    else if (target->parent->left == target)
                        target->parent->left = tmp;

                    if (target->left != NULL)
                    {
                        tmp->left = target->left;
                        target->left->parent = tmp;
                    }
                    tmp->color = RED;
                    delete(target);
                    //!!
                    if (nil->parent != NULL)
                    {
                        if ((nil->parent->color == BLACK) && (nil->parent->left != NULL) && (nil->parent->left->color == BLACK))
                        {
                            nil->parent->left->color = RED;
                            deleteRestructFivecase(nil->parent->parent, nil->parent, real_root);
                        }
                    }

                }
                else if ((target->right != NULL))
                {
                    tmp = getRightest(target->right);
                    //!!
                    if ((tmp->left == NULL) && (tmp->right == NULL) && (tmp->color == BLACK))
                        nil->parent = tmp->parent;
                    tmp->left = target->left;
                    // target->left->parent = tmp;

                    if (tmp->left != NULL)
                        deleteRestruct(tmp, tmp->right, 0, real_root);

                    if (tmp->parent->right == tmp)
                        tmp->parent->right = NULL;
                    else if (tmp->parent->left == tmp)
                        tmp->parent->left = NULL;
                    tmp->parent = target->parent;
                    if (target->parent->right == target)
                        target->parent->right = tmp;
                    else if (target->parent->left == target)
                        target->parent->left = tmp;

                    if (target->right != NULL)
                    {
                    
                        tmp->right = target->right;
                        target->right->parent = tmp;
                    }
                    tmp->color = RED;
                    delete(target);
                    //!!

                    if (nil->parent != NULL)
                    {
                        if ((nil->parent->color == BLACK) && (nil->parent->left != NULL) && (nil->parent->left->color == BLACK))
                        {
                            nil->parent->left->color = 0;
                            deleteRestructFivecase(nil->parent->parent, nil->parent, real_root);
                        }
                    }
                }
            }
            else if (target->color == BLACK)
            {
                if ((target->right == NULL) && (target->left == NULL))
                {
                    if (target->parent->right == target)
                    {
                        target->parent->right = NULL;
                        if (target->parent->left != NULL && target->parent->left->color == BLACK)
                            target->parent->left->color = RED;
                        deleteRestructFivecase(target->parent->parent, target->parent, real_root);
                    }
                    else if (target->parent->left == target)
                    {
                        target->parent->left = NULL;
                        if (target->parent->right != NULL && target->parent->right->color == BLACK)
                            target->parent->right->color = RED;
                        deleteRestructFivecase(target->parent->parent, target->parent, real_root);
                    }
                }
                else if (target->left != NULL)
                {
                    tmp = getRightest(target->left);
                    //!!
                    if ((tmp->left == NULL) && (tmp->right == NULL) && (tmp->color == BLACK))
                    {
                        nil->parent = tmp->parent;
                    }
                    tmp->right = target->right;
                    target->right->parent = tmp;

                    // tmp->left = target->left;
                    // target->left->parent = tmp;

                    if (tmp->left != NULL)
                        deleteRestruct(tmp, tmp->left, 1, real_root);
                    if (tmp->parent->right == tmp)
                        tmp->parent->right = NULL;
                    else if (tmp->parent->left == tmp)
                        tmp->parent->left = NULL;
                    tmp->parent = target->parent;
                    if (target->parent->right == target)
                        target->parent->right = tmp;
                    else if (target->parent->left == target)
                        target->parent->left = tmp;
                    // std::cout << "tmp : " << tmp->key << std::endl;
                    // std::cout << "tmp_right : " << tmp->right->key << std::endl;

                    // std::cout << "tmp_left : " << tmp->left->key << std::endl;
                    if (target->left != NULL)
                    {
                        tmp->left = target->left;
                        target->left->parent = tmp;
                    }
                    // if (target == nil->parent)
                    //     nil->parent->left->color = 0;
                    //!!
                    if (nil->parent != NULL)
                    {
                        if (((nil->parent->color == BLACK) && (nil->parent->left != NULL) && (nil->parent->left->color == BLACK)))
                        {
                            nil->parent->left->color = 0;
                            deleteRestructFivecase(nil->parent->parent, nil->parent, real_root);
                        }
                    }
                    delete(target);
                    tmp->color = BLACK;

                }
                else if ((target->right != NULL))
                {
                    tmp = getRightest(target->right);
                    //!!
                    if ((tmp->left == NULL) && (tmp->right == NULL) && (tmp->color == BLACK))
                        nil->parent = tmp->parent;
                    tmp->left = target->left;
                    // target->left->parent = tmp;

                    if (tmp->left != NULL)
                        deleteRestruct(tmp, tmp->right, 0, real_root);
                    if (tmp->parent->right == tmp)
                        tmp->parent->right = NULL;
                    else if (tmp->parent->left == tmp)
                        tmp->parent->left = NULL;
                    tmp->parent = target->parent;

                    // std::cout << "target : " << target->parent << std::endl;
                    // std::cout << "target : " << target->parent->right << std::endl;
                    // std::cout << "target : " << target->parent->left << std::endl;
                    
                    if ((target->parent != NULL) && target->parent->right == target)
                        target->parent->right = tmp;
                    else if ((target->parent != NULL) && target->parent->left == target)
                        target->parent->left = tmp;

                    if (target->right != NULL)
                    {
                        tmp->right = target->right;
                        target->right->parent = tmp;
                    }

                    //!!
                    if (nil->parent != NULL)
                    {
                        if ((nil->parent->color == BLACK) && (nil->parent->left != NULL) && (nil->parent->left->color == BLACK))
                        {
                            nil->parent->left->color = RED;
                            deleteRestructFivecase(nil->parent->parent, nil->parent, real_root);
                        }
                    }
                    delete(target);
                    tmp->color = BLACK;
                }
            }
            // new_root = getRoot(tmp);
            // real_root = new_root;
            delete(nil);
        }

        // void deleteNode(node<Key, Val, Compare>**real_root, node<Key, Val, Compare> *root, const Key& tk)
		// 	{
		// 		node<Key, Val, Compare> *newRoot;

		// 		if ((cmp(root->set.first, tk) == false) && (cmp(tk, root->set.first) == false))
		// 		{
		// 			if (root->left != NULL)
		// 			{
		// 				newRoot = getRightest(root->left);
		// 				newRoot->makeParentChildToMyChild(); // 부모와 자신자식의 라인을 이어준다. (이떄 newRoot 는 반드시 자식이 하나이므로 반드시 연결된다.)
						
		// 				////////////
		// 				if (newRoot->left != NULL)
		// 					newRoot->left->parent = newRoot->parent;
		// 				if (newRoot->right != NULL)
		// 					newRoot->right->parent = newRoot->parent;
		// 				///////////
						
		// 				newRoot->left = root->left;
		// 				newRoot->right = root->right;
		// 				newRoot->parent = root->parent;
		// 				if (root->parent != NULL)
		// 					root->parent->childChange(root, newRoot);
		// 				if (root->left != NULL)
		// 					root->left->parent = newRoot;
		// 				if (root->right != NULL)
		// 					root->right->parent = newRoot;
		// 				if (root == *real_root)
		// 					*real_root = newRoot;
		// 				delete (root);
		// 			}
		// 			else if (root->right != NULL)
		// 			{
		// 				newRoot = getleftest(root->right);
		// 				newRoot->makeParentChildToMyChild(); // 부모와 자신자식의 라인을 이어준다. (이떄 newRoot 는 반드시 자식이 하나이므로 반드시 연결된다.)
						
		// 				////////////
		// 				if (newRoot->left != NULL)
		// 					newRoot->left->parent = newRoot->parent;
		// 				if (newRoot->right != NULL)
		// 					newRoot->right->parent = newRoot->parent;
		// 				///////////
						
		// 				newRoot->left = root->left;
		// 				newRoot->right = root->right;
		// 				newRoot->parent = root->parent;
		// 				if (root->parent != NULL)
		// 					root->parent->childChange(root, newRoot);
		// 				if (root->left != NULL)
		// 					root->left->parent = newRoot;
		// 				if (root->right != NULL)
		// 					root->right->parent = newRoot;
		// 				if (root == *real_root)
		// 					*real_root = newRoot;
		// 				delete (root);
		// 			}
		// 			else // 양쪽 자식 모두 없다. (부모쪽 링크만 없애주면됨. 아래에 아무것도 없다)
		// 			{
		// 				root->makeParentChildToMyChild();
		// 				delete root;
		// 			}
		// 			return ;
		// 		}
		// 		if (cmp(root->set.first, tk) == false)
		// 			deleteNode(real_root, root->left, tk);
		// 		else if (cmp(root->set.first, tk))
		// 			deleteNode(real_root, root->right, tk);
		// 	}

        
        

        node<Key, Val, Compare>*		getLeft()
		{
			return (this->left);
		}
		node<Key, Val, Compare>*		getRight()
		{
			return (this->right);
		}
		node<Key, Val, Compare>*		getParent()
		{
			return (this->parent);
		}

    };

    template <typename Key, typename T, class Compare = less<Key> >
	class saver
	{
		public	:
			node<Key, T, Compare>* root;
		
			saver(node<Key, T, Compare>* root = NULL) : root(root){}
			~saver(){}
			saver(const saver<Key, T, Compare>& origin) : root(origin.root){}
			saver& operator=(const saver<Key, T, Compare>& origin)
			{
				this->root = origin.root;
				return (*this);
			}
	};

}

#endif