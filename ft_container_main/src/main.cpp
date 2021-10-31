/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghyunpark <sunghyunpark@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:15:39 by sunghyunpar       #+#    #+#             */
/*   Updated: 2021/10/31 17:29:50 by sunghyunpar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "tools.hpp"

int main(void)
{
    std::vector<int> vec_1;
    // std::vector<int> *vec_ptr;
    std::vector<int>::iterator iter_1;
    // std::vector<int> *vec_iter;
    
    vec_1.push_back(1);
    vec_1.push_back(2);
    vec_1.push_back(3);
    vec_1.push_back(4);
    vec_1.push_back(5);
    vec_1.push_back(6);

    std::cout << *(vec_1.begin()) << std::endl;
    std::cout << *(vec_1.end()) << std::endl;

    std::cout << *(vec_1.rbegin()) << std::endl;
    std::cout << *(vec_1.rend()) << std::endl;

    print_T(vec_1, 6);
}
