/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:28:09 by dmontoro          #+#    #+#             */
/*   Updated: 2023/10/02 10:32:50 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>

int main()
{
	std::string command = "";
	PhoneBook phonebook;
	while (command != "EXIT")
	{
		std::cout << "Please, enter a command: ";
		std::cin >> command;
		if (command == "ADD")
			phonebook.ADD();
		else if (command == "SEARCH")
			phonebook.SEARCH();
	}
}