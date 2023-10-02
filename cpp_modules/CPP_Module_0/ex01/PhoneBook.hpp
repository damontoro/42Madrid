/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:05:58 by dmontoro          #+#    #+#             */
/*   Updated: 2023/10/02 10:43:46 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	void ADD();
	void SEARCH();

private:
	const static int MAX_CONTACTS = 8;
	Contact contacts[MAX_CONTACTS];
	int index = 0;
	int contacts_count = 0;

	void	show_data();
	void	get_data(std::string& s);
};