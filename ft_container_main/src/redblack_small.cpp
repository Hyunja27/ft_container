
#include <iostream>

#define RED     false
#define BLACK   true

struct node{
    node * parent;
    node * left;
    node * right;
    unsigned int key;
    unsigned int val;
    //red == 0, black == 1
    bool         color;
};

struct Tree{
    node * root;
};

unsigned int elem_num;
Tree * tree = new Tree;
// node* nil = new node;
// nil->color = BLACK;
// nil->key = 0;
// nil->val = 0;

bool isSame(const unsigned int k_1, const unsigned int k_2)
{
    return (!(k_1 < k_2) && !(k_2 <k_1));
}

bool isFirstSmall(const unsigned int t1, const unsigned int t2)
{
	return ((t1 < t2));
}

bool isFirstEqualOrSmall(const unsigned int t1, const unsigned int t2)
{
	return (!(t2 < t1));
}

//key 보다 큰값중 가장 작은 값
node* getUpperBound(node *root, const unsigned int key)
{		
	if (isFirstEqualOrSmall(root->key, key))
	{
		if (root->right == NULL)
			return (NULL);
		else 
			return (getUpperBound(root->right, key));
	}
	else // key 가 더 작음.
	{
		if (root->left == NULL)
			return (root);
		else
			return (getUpperBound(root->left, key));
	}
}

		//key 보다 큰값중 가장 작거나 같은 값
node* getLowerBound(node *root, const unsigned int key)
{
	if (isSame(root->key, key)) // 값이 같다면 즉시 리턴
		return (root);
	
	if (isFirstSmall(root->key, key))
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

void left_lotate(node* target)
{
    node* tmp_root;

    if (target->parent == NULL)
    {
        tmp_root = target->right;
        target->right = tmp_root->left;
        if (tmp_root->left != NULL)
            tmp_root->left->parent = target;

        tmp_root->parent = NULL;        
        tmp_root->left = target;
        target->parent = tmp_root;

        tree->root = tmp_root;
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
    }
}

void right_lotate(node* target)
{
    node* tmp_root;
     
    if (target->parent == NULL)
    {
        tmp_root = target->left;
        target->left = tmp_root->right;
        if (tmp_root->right != NULL)
            tmp_root->right->parent = target;

        tmp_root->parent = NULL;        
        tmp_root->right = target;
        target->parent = tmp_root;

        tree->root = tmp_root;
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
    }

}

void lotater(node* target)
{
    node* grandparent = target->parent->parent;
    if ((grandparent->right != NULL) && (grandparent->right == target->parent))
    {
        if (target->parent->right == target)
        {
            target->parent->color = BLACK;
            grandparent->color = RED;
            left_lotate(grandparent);
        }
        else
        {
            target->color = BLACK;
            grandparent->color = RED;
            right_lotate(target->parent);
            left_lotate(grandparent);
        }
    }
    else if ((grandparent->left != NULL) && (grandparent->left == target->parent))
    {
        if (target->parent->left == target)
        {
            target->parent->color = BLACK;
            grandparent->color = RED;
            right_lotate(grandparent);
        }
        else
        {
            target->color = BLACK;
            grandparent->color = RED;
            left_lotate(target->parent);
            right_lotate(grandparent);
        }
    }
}

node* getRightest(node* base)
{
    if (base == NULL || base->right == NULL)
        return (base);
    return (getRightest(base->right));
}

node* getleftest(node* base)
{
    if (base == NULL || base->left == NULL)
        return (base);
    return (getleftest(base->left));
}

node* uncle_getter(node* target)
{   
    node* grandparent = target->parent->parent;

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

void logic_checker(node* inserted)
{
    if (inserted->parent->color == BLACK)
        return ;
    else
    {
        node* uncle = uncle_getter(inserted);
        if (uncle == NULL || uncle->color == BLACK) 
            lotater(inserted);
        else
        {
            inserted->parent->color = BLACK;
            uncle->color = BLACK;
            if (inserted->parent->parent->parent == NULL)
                return ;
            inserted->parent->parent->color = RED;
            logic_checker(inserted->parent->parent);
        }
    }
}

void insert(node* &base, node* target)
{
    if (elem_num == 0)
    {
        base = target;
        elem_num++;
        base->right = NULL;
        base->left = NULL;
        base->parent = NULL;
        base->color = BLACK;
        return;
    }
    else
    {
        if (target->key < base->key)
        {
            if (base->left == NULL)
            {
                base->left = target;
                target->color = RED;
                target->right = NULL;
                target->left = NULL;
                target->parent = base;
                elem_num++;
                logic_checker(target);
            }
            else
                insert(base->left, target);
        }
        else
        {
            if (base->right == NULL)
            {
                base->right = target;
                target->color = RED;
                target->right = NULL;
                target->left = NULL;
                target->parent = base;
                elem_num++;
                logic_checker(target);
            }
            else
                insert(base->right, target);
        }
    }
}

node* find(node* base, unsigned int target_key)
{
    if (base == NULL)
        return NULL;
    if (base->key == target_key)
        return base;
    else if (target_key < base->key)
        return find(base->left, target_key);
    else
        return find(base->right, target_key);
    return NULL;
}

void deleteRestructFivecase(node* p, node* c)
{
    bool islefted = 0;
    node* s = NULL;
    node* n_near = NULL;
    node* n_far = NULL;

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
            left_lotate(p);
            s->color = p->color;
            p->color = BLACK;
            n_far->color = BLACK;
        }
        else
        {
            right_lotate(p);
            s->color = p->color;
            p->color = BLACK;
            n_far->color = BLACK;
        }
    }
    else if ((s->color == BLACK) && (n_near->color == RED) && (n_far->color == BLACK))
    {
        if (islefted)
        {
            right_lotate(s);
            s->color = RED;
            n_near->color = BLACK;
            deleteRestructFivecase(p, c);
        }
        else
        {
            left_lotate(s);
            s->color = RED;
            n_near->color = BLACK;
            deleteRestructFivecase(p, c);
        }
    }
    else if ((p->color == BLACK) && (s->color == BLACK) && (n_near->color == BLACK) && (n_far->color == BLACK))
    {
        s->color = RED;
        deleteRestructFivecase(p->parent, c->parent);
    }
    else if ((p->color == BLACK) && (s->color == RED) && (n_near->color == BLACK) && (n_far->color == BLACK))
    {
        if (islefted)
        {
            left_lotate(p);
            s->color = BLACK;
            p->color = RED;
        }
        else
        {
            left_lotate(p);
            s->color = BLACK;
            p->color = RED;
        }
    }

}

void deleteRestruct(node* hooim, node* h_jasic, bool isLeft)
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
            node* p = hooim->parent;
            node* c = h_jasic;
            deleteRestructFivecase(p, c);
        }
    }
}

void deleteNode(unsigned int target_key)
{
    node* target = find(tree->root, target_key);
    node* tmp;
    node* nil = new node;

    nil->color = BLACK;
    nil->key = 0;
    nil->right = NULL;
    nil->left = NULL;
    nil->parent = NULL;

    // std::cout << std::endl << "deleting : " << target->key << std::endl << std::endl << std::endl;

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
            

            if (tmp->left != NULL)
                deleteRestruct(tmp, tmp->left, 1);
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
                if ((nil->parent->color == BLACK) && (nil->parent->left != NULL) && (nil->parent->left->color == BLACK))
                {
                    nil->parent->left->color = RED;
                    deleteRestructFivecase(nil->parent->parent, nil->parent);
                }


        }
        else if ((target->left == NULL) && (target->right != NULL))
        {
            tmp = getRightest(target->right);

            //!!
            if ((tmp->left == NULL) && (tmp->right == NULL) && (tmp->color == BLACK))
                nil->parent = tmp->parent;

            tmp->left = target->left;
            target->left->parent = tmp;

            if (tmp->left != NULL)
                deleteRestruct(tmp, tmp->right, 0);
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
                if ((nil->parent->color == BLACK) && (nil->parent->left != NULL) && (nil->parent->left->color == BLACK))
                {
                    nil->parent->left->color = RED;
                    deleteRestructFivecase(nil->parent->parent, nil->parent);
                }
        }
        elem_num--;
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
                deleteRestructFivecase(target->parent->parent, target->parent);
            }
            else if (target->parent->left == target)
            {
                target->parent->left = NULL;
                if (target->parent->right != NULL && target->parent->right->color == BLACK)
                    target->parent->right->color = RED;
                deleteRestructFivecase(target->parent->parent, target->parent);
            }
        }
        else if (target->left != NULL)
        {
            tmp = getRightest(target->left);

            //!!
            if ((tmp->left == NULL) && (tmp->right == NULL) && (tmp->color == BLACK))
                nil->parent = tmp->parent;

            tmp->right = target->right;
            target->right->parent = tmp;

            
            if (tmp->left != NULL)
                deleteRestruct(tmp, tmp->left, 1);

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
            delete(target);

            //!!
            if (nil->parent != NULL)
                if ((nil->parent->color == BLACK) && (nil->parent->left != NULL) && (nil->parent->left->color == BLACK))
                {
                    nil->parent->left->color = RED;
                    deleteRestructFivecase(nil->parent->parent, nil->parent);
                }

            tmp->color = BLACK;
            
        }
        else if ((target->left == NULL) && (target->right != NULL))
        {
            tmp = getRightest(target->right);

            //!!
            if ((tmp->left == NULL) && (tmp->right == NULL) && (tmp->color == BLACK))
                nil->parent = tmp->parent;

            tmp->left = target->left;
            target->left->parent = tmp;
            if (tmp->left != NULL)
                deleteRestruct(tmp, tmp->right, 0);
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
            delete(target);


            //!!
            if (nil->parent != NULL)
                if ((nil->parent->color == BLACK) && (nil->parent->left != NULL) && (nil->parent->left->color == BLACK))
                {
                    nil->parent->left->color = RED;
                    deleteRestructFivecase(nil->parent->parent, nil->parent);
                }

            tmp->color = BLACK;
        }
        elem_num--;
    }
}

void print_all(node* base)
{
    std::cout << "[" << base->key << " : " << base->val << "]" << std::endl;
    if (base->left != NULL)
        print_all(base->left);
    if (base->right != NULL)
        print_all(base->right);
}

void printBT(const std::string& prefix, const node* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "l├──" : "r└──" );

        // print the value of the node
        std::cout << node->key << ":" << (node->color ? "Black":"Red") << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? " │   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? " │   " : "    "), node->right, false);
    }
}

void printBT(const node* node)
{
    printBT("", node, false);    
}

int main(void)
{
    node * newnode1 = new node;
    node * newnode2 = new node;
    node * newnode3 = new node;
    node * newnode4 = new node;
    node * newnode5 = new node;
    node * newnode6 = new node;
    node * newnode7 = new node;
    node * newnode8 = new node;
    node * newnode9 = new node;
    node * newnode10 = new node;
    node * newnode11 = new node;
    node * newnode12 = new node;
    node * newnode13 = new node;
    node * newnode14 = new node;
    node * newnode15 = new node;

    elem_num = 0;
    tree->root = NULL;

    newnode1->key = 4;
    newnode1->val = 11;

    newnode2->key = 8;
    newnode2->val = 22;

    newnode3->key = 12;
    newnode3->val = 33;

    newnode4->key = 16;
    newnode4->val = 44;

    newnode5->key = 20;
    newnode5->val = 55;

    newnode6->key = 24;
    newnode6->val = 66;

    newnode7->key = 28;
    newnode7->val = 77;

    newnode8->key = 32;
    newnode8->val = 88;

    newnode9->key = 36;
    newnode9->val = 99;

    newnode10->key = 40;
    newnode10->val = 100;

    newnode11->key = 44;
    newnode11->val = 110;

    newnode12->key = 48;
    newnode12->val = 120;

    newnode13->key = 52;
    newnode13->val = 130;

    newnode14->key = 56;
    newnode14->val = 140;

    newnode15->key = 60;
    newnode15->val = 150;


    // == order ==
    insert(tree->root, newnode1);
    insert(tree->root, newnode2);
    insert(tree->root, newnode3);
    insert(tree->root, newnode4);
    insert(tree->root, newnode5);
    insert(tree->root, newnode6);
    insert(tree->root, newnode7);
    insert(tree->root, newnode8);
    insert(tree->root, newnode9);
    insert(tree->root, newnode10);
    insert(tree->root, newnode11);
    insert(tree->root, newnode12);
    insert(tree->root, newnode13);
    insert(tree->root, newnode14);
    insert(tree->root, newnode15);

    // == disorder ==
    // insert(tree->root, newnode2);
    // insert(tree->root, newnode11);
    // insert(tree->root, newnode7);
    // insert(tree->root, newnode6);
    // insert(tree->root, newnode8);
    // insert(tree->root, newnode13);
    // insert(tree->root, newnode4);
    // insert(tree->root, newnode9);
    // insert(tree->root, newnode1);
    // insert(tree->root, newnode14);
    // insert(tree->root, newnode5);
    // insert(tree->root, newnode15);
    // insert(tree->root, newnode3);
    // insert(tree->root, newnode10);
    // insert(tree->root, newnode12);

    // deleteNode(newnode12->key);
    deleteNode(newnode7->key);
    deleteNode(newnode8->key);
    deleteNode(newnode10->key);
    // deleteNode(newnode9->key);




    // print_all(tree->root);
    printBT(tree->root);

    std::cout << std::endl << std::endl << std::endl << "elem_num : " << elem_num << std::endl;
    std::cout << std::endl << "root : " << tree->root->key << std::endl;
    // std::cout << std::endl << "find_output : " << tmp->key << std::endl;

}

//==============================//
