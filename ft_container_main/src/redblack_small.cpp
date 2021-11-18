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

void left_lotate(node* target)
{
    node* tmp_root;

    if (target->parent == NULL)
    {
        tmp_root = target->right;
        tmp_root->parent = NULL;
        target->right = tmp_root->left;
        tmp_root->left = target;
        target->parent = tmp_root;
    }
    else
    {
        tmp_root = target->right;
        tmp_root->parent = target->parent;
        target->right = tmp_root->left;
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
        tmp_root->parent = NULL;
        target->left = tmp_root->right;
        tmp_root->right = target;
        target->parent = tmp_root;
    }
    else
    {
        tmp_root = target->left;
        tmp_root->parent = target->parent;
        target->left = tmp_root->right;
        tmp_root->right = target;
        target->parent = tmp_root;
    }

}

void lotater(node* target)
{
    node* grandparent = target->parent->parent;

    if (grandparent->right == target->parent)
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
    else
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

node* uncle_getter(node* target)
{   
    node* grandparent = target->parent->parent;

    if (grandparent->left == target->parent)
        if (grandparent->right == NULL)
            return NULL;
        else
            return grandparent->right;
    else
        if (grandparent->left == NULL)
            return NULL;
        else
            return grandparent->left;
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

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->key << ":" << (node->color ? "Black":"Red") << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
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

    elem_num = 0;
    tree->root = NULL;

    newnode1->key = 1;
    newnode1->val = 11;

    newnode2->key = 7;
    newnode2->val = 22;

    newnode3->key = 13;
    newnode3->val = 33;

    newnode4->key = 15;
    newnode4->val = 44;

    newnode5->key = 19;
    newnode5->val = 55;

    newnode6->key = 30;
    newnode6->val = 66;

    newnode7->key = 48;
    newnode7->val = 77;

    newnode8->key = 61;
    newnode8->val = 88;

    // == order ==
    insert(tree->root, newnode1);
    insert(tree->root, newnode2);
    insert(tree->root, newnode3);
    insert(tree->root, newnode4);
    insert(tree->root, newnode5);
    insert(tree->root, newnode6);
    insert(tree->root, newnode7);
    insert(tree->root, newnode8);


    // == disorder ==
    // insert(tree->root, newnode2);
    // insert(tree->root, newnode7);
    // insert(tree->root, newnode6);
    // insert(tree->root, newnode8);
    // insert(tree->root, newnode4);
    // insert(tree->root, newnode1);
    // insert(tree->root, newnode5);
    // insert(tree->root, newnode3);


    // print_all(tree->root);
    printBT(tree->root);

}



//==============================//
