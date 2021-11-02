/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghyunpark <sunghyunpark@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:15:39 by sunghyunpar       #+#    #+#             */
/*   Updated: 2021/11/02 19:14:50 by sunghyunpar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "tools.hpp"
#include "container/vector.hpp"
#include "iterator/vector_iterator.hpp"

int main(void)
{
    ft::vector<int> vec_1;
    std::vector<int> vec_2;
    // ft::vector<int>::iterator iter_1;
    // ft::vector<int>::reverse_iterator iter_2;
    // // std::vector<int> *vec_iter;
    
    vec_1.push_back(1);
    vec_1.push_back(2);
    vec_1.push_back(3);
    vec_1.push_back(4);
    vec_1.push_back(5);
    vec_1.push_back(6);

    vec_2.push_back(1);
    vec_2.push_back(2);
    vec_2.push_back(3);
    vec_2.push_back(4);
    vec_2.push_back(5);
    vec_2.push_back(6);
    

    // std::cout << *(vec_1.begin()) << std::endl;
    // std::cout << *(vec_1.end()) << std::endl;

    // std::cout << *(vec_1.rbegin()) << std::endl;
    // std::cout << *(vec_1.rend()) << std::endl;

    std::cout << std::endl;
    std::cout << "========================== my vec ===================== " << std::endl;
        
    // std::cout << vec_1[0] << std::endl;
    // std::cout << vec_1[1] << std::endl;
    // std::cout << vec_1[2] << std::endl;
    // std::cout << vec_1[3] << std::endl;
    // std::cout << vec_1[4] << std::endl;
    // std::cout << vec_1[5] << std::endl;
    // print_T(vec_1, 3);


    std::cout << std::endl;
    std::cout << "========================== real vec ===================== " << std::endl;

    // std::cout << vec_2[0] << std::endl;
    // std::cout << vec_2[1] << std::endl;
    // std::cout << vec_2[2] << std::endl;
    // std::cout << vec_2[3] << std::endl;
    // std::cout << vec_2[4] << std::endl;
    // std::cout << vec_2[5] << std::endl;
    // std::cout << vec_2[6] << std::endl;
    // std::cout << vec_2[7] << std::endl;
    // std::cout << vec_2[8] << std::endl;
    print_T(vec_2, 6);
    

    

    return 0;
}
