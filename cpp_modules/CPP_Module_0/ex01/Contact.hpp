/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:06:33 by dmontoro          #+#    #+#             */
/*   Updated: 2023/12/14 18:54:30 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Contact
{
public:
	Contact();
	Contact(std::string first_name, std::string last_name, std::string nickname,
					int phone_number, std::string darkest_secret);
	~Contact();
	void		print();
	std::string get_first_name();
	std::string get_last_name();
	std::string get_nickname();
	int 		get_phone_number();
	std::string get_darkest_secret();

private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	int			phone_number;
	std::string darkest_secret;
};