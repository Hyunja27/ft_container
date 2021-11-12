/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghyunpark <sunghyunpark@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:15:39 by sunghyunpar       #+#    #+#             */
/*   Updated: 2021/11/12 17:56:09 by sunghyunpar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <vector>
#include <stack>
#include <map>

#include "tools.hpp"
#include "container/vector.hpp"
#include "container/stack.hpp"
#include "iterator/vector_iterator.hpp"




int main(void)
{
	// std::pair<int, int> a;
    // ft::vector<int> vec_1;
	// ft::vector<int>::iterator iter_1;
    // std::vector<int> vec_2;
	// std::vector<int>::iterator iter_2;
	// ft::stack<int> stack_1;
    
	// // ft::vector<int>::iterator iter_1;
    // // ft::vector<int>::reverse_iterator iter_2;
    // // // std::vector<int> *vec_iter;
    
    // vec_1.push_back(1);
    // vec_1.push_back(2);
    // vec_1.push_back(3);
    // vec_1.push_back(4);
    // vec_1.push_back(5);
    // vec_1.push_back(6);
    // vec_1.push_back(7);
    // vec_1.push_back(8);
    // vec_1.push_back(9);
    // vec_1.push_back(10);
    // vec_1.push_back(11);
    // vec_1.push_back(12);

    // vec_2.push_back(1);
    // vec_2.push_back(2);
    // vec_2.push_back(3);
    // vec_2.push_back(4);
    // vec_2.push_back(5);
    // vec_2.push_back(6);
    // vec_2.push_back(7);
    // vec_2.push_back(8);
    // vec_2.push_back(9);
    // vec_2.push_back(10);
    // vec_2.push_back(11);
    // vec_2.push_back(12);
    

    // // std::cout << *(vec_1.begin()) << std::endl;
    // // std::cout << *(vec_1.end()) << std::endl;

    // // std::cout << *(vec_1.rbegin()) << std::endl;
    // // std::cout << *(vec_1.rend()) << std::endl;

    // std::cout << std::endl;
    // std::cout << "========================== my vec ===================== " << std::endl;
        
    // std::cout << vec_1[0] << std::endl;
    // std::cout << vec_1[1] << std::endl;
    // std::cout << vec_1[2] << std::endl;
    // std::cout << vec_1[3] << std::endl;
    // std::cout << vec_1[4] << std::endl;
    // std::cout << vec_1[5] << std::endl;
    // std::cout << vec_2[6] << std::endl;
    // std::cout << vec_2[7] << std::endl;
    // std::cout << vec_2[8] << std::endl;
    // std::cout << vec_2[9] << std::endl;
    // std::cout << vec_2[10] << std::endl;
    
    // std::cout << std::endl;
    
    // // std::cout << vec_1.capacity() << std::endl;
    
    // // print_T(vec_1, 12);
	// iter_1 = vec_1.begin();
	// ft::vector<int>::iterator iter_1_tmp = iter_1 + 3;

	// for (int i = 0; i < 12; i++)
	// 	std::cout << iter_1[i] << "|";

	// // vec_1.erase(iter_1_tmp);

	// // for (int i = 0; i < 12; i++)
	// // 	std::cout << iter_1[i] << "|";

	// // vec_1.erase(6);
	


    // std::cout << std::endl;
    // std::cout << "========================== real vec ===================== " << std::endl;

    // std::cout << vec_2[0] << std::endl;
    // std::cout << vec_2[1] << std::endl;
    // std::cout << vec_2[2] << std::endl;
    // std::cout << vec_2[3] << std::endl;
    // std::cout << vec_2[4] << std::endl;
    // std::cout << vec_2[5] << std::endl;
    // std::cout << vec_2[6] << std::endl;
    // std::cout << vec_2[7] << std::endl;
    // std::cout << vec_2[8] << std::endl;
    // std::cout << vec_2[9] << std::endl;
    // std::cout << vec_2[10] << std::endl;
    
    // std::cout << std::endl;
    // // std::cout << vec_2.capacity() << std::endl;

    // // print_T(vec_2, 12);
	// iter_2 = vec_2.begin();
	// // std::vector<int>::iterator iter_2_tmp = iter_2 + 3;
	
	// for (int j = 0; j < 12; j++)
	// 	std::cout << iter_1[j] << "|";

	// stack_1.push(1);
	// stack_1.push(1);
	// stack_1.push(1);
	// stack_1.push(1);
	// stack_1.push(1);
	// stack_1.push(1);
	// stack_1.push(1);
	// stack_1.push(1);
	// stack_1.push(1);
	// stack_1.push(1);
	// stack_1.push(100);

	// std::cout << stack_1.size() << std::endl;
	// std::cout << stack_1.top() << std::endl;
	// std::cout << stack_1.pop() << std::endl;
	// std::cout << stack_1.size() << std::endl;
    
    
	std::map<char, double> test_map;

	test_map['a'] = 0.1;
	test_map['b'] = 0.2;
	test_map['c'] = 0.3;
	test_map['d'] = 0.4;
	test_map['e'] = 0.5;
	test_map['f'] = 0.6;
	test_map['g'] = 0.7;

	std::map<char, double>::iterator it;

	it = test_map.begin();

	for (; it != test_map.end(); it++)
		std::cout << it->first << " -> " << it->second << std::endl;

	std::cout << std::endl << std::endl << std::endl << std::endl;
	std::cout << "size: " << test_map.size() << std::endl;
	std::cout << "max_size: " << test_map.max_size() << std::endl << std::endl;

	std::pair<std::map<char, double>::iterator, bool> tmp;
	tmp = test_map.insert(std::pair<char, double>('a', 9.999));

	std::cout << std::endl << std::endl << std::endl << std::endl;
	
	std::cout << tmp.first->first << " => " << tmp.second << std::endl;

	std::cout << std::endl << std::endl << std::endl << std::endl;

	it = test_map.begin();
	for (; it != test_map.end(); it++)
		std::cout << it->first << " -> " << it->second << std::endl;
	test_map.clear();
	std::cout << "size: " << test_map.size() << std::endl;
	std::cout << "max_size: " << test_map.max_size() << std::endl << std::endl;

    return 0;
}


// #define TESTED_TYPE std::string
// #define TESTED_NAMESPACE ft


// template <typename T>
// void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
// {
// 	const T_SIZE_TYPE size = vct.size();
// 	const T_SIZE_TYPE capacity = vct.capacity();
// 	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
// 	// Cannot limit capacity's max value because it's implementation dependent

// 	std::cout << "size: " << size << std::endl;
// 	std::cout << "capacity: " << isCapacityOk << std::endl;
// 	std::cout << "max_size: " << vct.max_size() << std::endl;
// 	if (print_content)
// 	{
// 		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
// 		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
// 		std::cout << std::endl << "Content is:" << std::endl;
// 		for (; it != ite; ++it)
// 			std::cout << "- " << *it << std::endl;
// 	}
// 	std::cout << "###############################################" << std::endl;
// }


// void	checkErase(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct,
// 					TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator const &it)
// {
// 	static int i = 0;
// 	std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
// 	printSize(vct);
// }

// int		main(void)
// {
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);

// 	for (unsigned long int i = 0; i < vct.size(); ++i)
// 		vct[i] = std::string((vct.size() - i), i + 65);
// 	printSize(vct);

// 	checkErase(vct, vct.erase(vct.begin() + 2));

// 	checkErase(vct, vct.erase(vct.begin()));
// 	checkErase(vct, vct.erase(vct.end() - 1));

// 	checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3));
// 	checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1));

// 	vct.push_back("Hello");
// 	vct.push_back("Hi there");
// 	printSize(vct);
// 	checkErase(vct, vct.erase(vct.end() - 3, vct.end()));

// 	vct.push_back("ONE");
// 	vct.push_back("TWO");
// 	vct.push_back("THREE");
// 	vct.push_back("FOUR");
// 	printSize(vct);
// 	checkErase(vct, vct.erase(vct.begin(), vct.end()));

// 	return (0);
// }

#define TESTED_NAMESPACE ft
// #define TESTED_TYPE foo
// #define TESTED_TYPE int
#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

class foo {
	public:
		foo(void) { };
		~foo(void) { };
		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
		foo &operator=(int src) { this->value = src; return *this; };
		int getValue(void) const { return this->value; };
	private:
		int	value;
};

std::ostream	&operator<<(std::ostream &o, foo const &bar) {
	o << bar.getValue();
	return o;
}

template <class T, class Alloc>
void	cmp(const TESTED_NAMESPACE::vector<T, Alloc> &lhs, const TESTED_NAMESPACE::vector<T, Alloc> &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

template <typename Ite_1, typename Ite_2>
void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
{
	std::cout << (first < second) << std::endl;
	std::cout << (first <= second) << std::endl;
	std::cout << (first > second) << std::endl;
	std::cout << (first >= second) << std::endl;
	if (redo)
		ft_eq_ope(second, first, 0);
}

// int		main(void)
// {
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(5);
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
// 	const int cut = 3;

// 	for (unsigned long int i = 0; i < vct.size(); ++i)
// 		vct[i] = (vct.size() - i) * 7;
// 	printSize(vct);

// 	vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
// 	printSize(vct2);
// 	vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
// 	printSize(vct2);
// 	vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
// 	printSize(vct2);

// 	std::cout << "insert return:" << std::endl;

// 	std::cout << *vct2.insert(vct2.end(), 42) << std::endl;
// 	std::cout << *vct2.insert(vct2.begin() + 5, 84) << std::endl;
// 	std::cout << "----------------------------------------" << std::endl;

// 	printSize(vct2);
// 	return (0);
// }


// int		main(void)
// {
// 	const int size = 5;
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it = vct.rbegin();
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator ite = vct.rbegin();

// 	for (int i = 0; i < size; ++i)
// 	{
// 		std::cout << &(it[i]) - 1 << std::endl; 
// 		it[i] = (size - i)  * 5;
// 	}

// 	std::cout << "start : " << &(*it) << std::endl; 

// 	it = it + 5;

// 	std::cout << std::endl << " + 5 : " << &(*it) << std::endl; 
	
// 	it = 1 + it;

// 	std::cout << std::endl << " + 1 : " << &(*it) << std::endl; 
	
// 	it = it - 4;

// 	std::cout << std::endl << " - 4 : " << &(*it) << std::endl; 
	
// 	std::cout << *(it += 2) << std::endl;
// 	std::cout << *(it -= 1) << std::endl;

// 	*(it -= 2) = 42;
// 	*(it += 2) = 21;

// 	std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

// 	std::cout << "(it == const_it): " << (ite == it) << std::endl;
// 	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
// 	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

// 	printSize(vct, true);
// 	return (0);
// }