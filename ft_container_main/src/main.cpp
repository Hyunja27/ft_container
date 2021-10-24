/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunghyunpark <sunghyunpark@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:15:39 by sunghyunpar       #+#    #+#             */
/*   Updated: 2021/10/24 18:46:19 by sunghyunpar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "tools.hpp"

int main(void)
{
    int test_arr[] = {0, 1, 2, 3, 4, 5};
    char test_arr2[] = {'a', 'b', 'c', 'd'};
    std::vector<std::string> test_arr3;

    print_T(test_arr, 6);
    print_T(test_arr2, 4);

    test_arr3.push_back("skim");
    test_arr3.push_back("spark");
    test_arr3.push_back("jaeskim");
    test_arr3.push_back("hyunlee");
    test_arr3.push_back("yjung");
    
    print_T(test_arr3, 20);

}
