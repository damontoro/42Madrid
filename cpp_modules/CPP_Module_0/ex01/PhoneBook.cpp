/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:13:30 by dmontoro          #+#    #+#             */
/*   Updated: 2023/10/02 10:44:01 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <math.h>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
	this->contacts_count = 0;
}

PhoneBook::~PhoneBook(){}

void PhoneBook::get_data(std::string& s){
	s = "";
	while(s == "")
		std::cin >> s;
}

void PhoneBook::ADD()
{
	std::string first_name = "";
	std::string last_name = "";
	std::string nickname = "";
	std::string phone_number = "";
	std::string darkest_secret = "";
	
	std::cout << "First name: ";
	get_data(first_name);
	std::cout << "Last name: ";
	get_data(last_name);
	std::cout << "Nickname: ";
	get_data(nickname);
	std::cout << "Phone number: ";
	get_data(phone_number);
	std::cout << "Darkest secret: ";
	get_data(darkest_secret);
	contacts[index] = Contact(first_name, last_name, nickname, phone_number, darkest_secret);
	index = (index + 1) % MAX_CONTACTS;
	contacts_count = std::min(contacts_count + 1, MAX_CONTACTS);
}
void PhoneBook::show_data()
{
	for(int i = 0; i < this->contacts_count; i++)
	{
		std::cout << std::setw(10) << std::right << i << "|";
		std::cout << std::setw(10) << std::right << this->contacts[i].get_first_name() << "|";
		std::cout << std::setw(10) << std::right << this->contacts[i].get_last_name() << "|";
		std::cout << std::setw(10) << std::right << this->contacts[i].get_nickname() << std::endl;
	}
}

void PhoneBook::SEARCH()
{
	show_data();
	int index = -1;
	std::cout << "Enter index you want to search: ";
	while (index < 0 || index >= this->contacts_count)
	{
		std::cin >> index;
		if (index < 0 || index >= this->contacts_count)
			std::cout << "Index out of range, try again: ";
	}
	this->contacts[index].print();
}
