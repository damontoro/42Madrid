/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:11:04 by dmontoro          #+#    #+#             */
/*   Updated: 2023/12/14 18:54:52 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"

Contact::Contact(){
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->darkest_secret = "";
}

Contact::Contact(std::string first_name, std::string last_name, std::string nickname,
					int phone_number, std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}
Contact::~Contact(){}

void Contact::print()
{
	std::cout << "First name: " << this->first_name << std::endl;
	std::cout << "Last name: " << this->last_name << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phone_number << std::endl;
	std::cout << "Darkest secret: " << this->darkest_secret << std::endl;
}


std::string Contact::get_first_name()
{
	return this->first_name.size() > 10 ? this->first_name.substr(0, 9) + "." : this->first_name;
}

std::string Contact::get_last_name()
{
	return this->last_name.size() > 10 ? this->last_name.substr(0, 9) + "." : this->last_name;
}

std::string Contact::get_nickname()
{
	return this->nickname.size() > 10 ? this->nickname.substr(0, 9) + "." : this->nickname;
}

int Contact::get_phone_number()
{
	return (this->phone_number);
}

std::string Contact::get_darkest_secret()
{
	return (this->darkest_secret);
}