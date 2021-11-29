/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghyunpark <sunghyunpark@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:15:39 by sunghyunpar       #+#    #+#             */
/*   Updated: 2021/11/30 00:51:15 by sunghyunpar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include "common.hpp"


// template<class Key, class Val>
// void printBT(const std::string& prefix, const ft::node<Key, Val>* node, bool isLeft)
// {
//     if( node != nullptr )
//     {
//         std::cout << prefix;

//         std::cout << (isLeft ? "l├──" : "r└──" );

//         // print the value of the node
//         std::cout << node->set.first << ":" << (node->color ? "Black":"Red") << std::endl;

//         // enter the next tree level - left and right branch
//         printBT( prefix + (isLeft ? " │   " : "    "), node->left, true);
//         printBT( prefix + (isLeft ? " │   " : "    "), node->right, false);
//     }
// }

// template<class Key, class Val>
// void printBT(const ft::node<Key, Val>* node)
// {
//     printBT("", node, false);    
// }

#define T1 char
#define T2 int
typedef _pair<const T1, T2> T3;

template <class MAP>
void	cmp(const MAP &lhs, const MAP &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

int		main(void)
{
	TESTED_NAMESPACE::map<T1, T2> mp1;
	TESTED_NAMESPACE::map<T1, T2> mp2;

	mp1['a'] = 2; mp1['b'] = 3; mp1['c'] = 4; mp1['d'] = 5;
	mp2['a'] = 2; mp2['b'] = 3; mp2['c'] = 4; mp2['d'] = 5;

	cmp(mp1, mp1); // 0
	cmp(mp1, mp2); // 1

	mp2['e'] = 6; mp2['f'] = 7; mp2['h'] = 8; mp2['h'] = 9;

	cmp(mp1, mp2); // 2
	cmp(mp2, mp1); // 3

	(++(++mp1.begin()))->second = 42;

	cmp(mp1, mp2); // 4
	cmp(mp2, mp1); // 5

	swap(mp1, mp2);

	cmp(mp1, mp2); // 6
	cmp(mp2, mp1); // 7

	return (0);
}



// printBT(iter.getSave()->root);
	
	
