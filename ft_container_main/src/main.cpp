/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghyunpark <sunghyunpark@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:15:39 by sunghyunpar       #+#    #+#             */
/*   Updated: 2021/11/25 02:16:29 by sunghyunpar      ###   ########.fr       */
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


#define T1 int
#define T2 std::string
typedef _pair<const T1, T2> T3;

static int iter = 0;

template <typename MAP, typename U>
void	ft_erase(MAP &mp, U param)
{

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param);
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_erase(MAP &mp, U param, V param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	// std::cout << "???????" << std::endl;

	mp.erase(param, param2);
	printSize(mp);
}

int		main(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	printSize(mp);

	ft_erase(mp, ++mp.begin());

	ft_erase(mp, mp.begin());
	ft_erase(mp, --mp.end());

	ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
	ft_erase(mp, --(--(--mp.end())), --mp.end());

	// mp[10] = "Hello";
	// mp[11] = "Hi there";
	// printSize(mp);
	// ft_erase(mp, --(--(--mp.end())), mp.end());

	// mp[12] = "ONE";
	// mp[13] = "TWO";
	// mp[14] = "THREE";
	// mp[15] = "FOUR";
	// printSize(mp);
	// ft_erase(mp, mp.begin(), mp.end());

	return (0);
}

	

// printBT(iter.getSave()->root);
	
	
