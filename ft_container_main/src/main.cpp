/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghyunpark <sunghyunpark@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:15:39 by sunghyunpar       #+#    #+#             */
/*   Updated: 2021/11/29 19:51:35 by sunghyunpar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include "common.hpp"


template<class Key, class Val>
void printBT(const std::string& prefix, const ft::node<Key, Val>* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "l├──" : "r└──" );

        // print the value of the node
        std::cout << node->set.first << ":" << (node->color ? "Black":"Red") << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? " │   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? " │   " : "    "), node->right, false);
    }
}

template<class Key, class Val>
void printBT(const ft::node<Key, Val>* node)
{
    printBT("", node, false);    
}
#include "common.hpp"

#define T1 char

template <class SET>
void	cst(const SET &lhs, const SET &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

int		main(void)
{
	TESTED_NAMESPACE::multiset<T1> st1;
	TESTED_NAMESPACE::multiset<T1> st2;

	st1.insert('a');
	st1.insert('b');
	st1.insert('c');
	st1.insert('d');
	st2.insert('a');
	st2.insert('b');
	st2.insert('c');
	st2.insert('d');

	cst(st1, st1); // 0
	cst(st1, st2); // 1

	st2.insert('e');
	st2.insert('f');
	st2.insert('h');
	st2.insert('h');

	cst(st1, st2); // 2
	cst(st2, st1); // 3

	swap(st1, st2);

	cst(st1, st2); // 4
	cst(st2, st1); // 5

	return (0);
}


// printBT(iter.getSave()->root);
	
	
