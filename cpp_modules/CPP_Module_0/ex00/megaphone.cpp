/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoro <dmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 09:54:31 by dmontoro          #+#    #+#             */
/*   Updated: 2023/11/30 15:50:08 by dmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		std::string s;
		for (int i = 1; i < argc; i++)
		{
			s = argv[i];
			transform(s.begin(), s.end(), s.begin(), ::toupper);
			std::cout << s;
			if (i < argc - 1)
				std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (0);
}