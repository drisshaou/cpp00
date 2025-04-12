/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <drhaouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:17:14 by drhaouha          #+#    #+#             */
/*   Updated: 2025/04/10 20:05:47 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	getContactIndex( PhoneBook *pbk )
{
	std::string	valid;
	std::string	index;
	int			i;

	valid = "n ";
	i = -1;
	while ( true && (*pbk).getRegistered() != -1 )
	{
		std::cout << "Enter a" << valid << "index" << ":" << std::endl;
		valid = "n ";
		std::getline( std::cin, index );
		if ( index.size() != 1 || !std::isdigit( index[0] )
			|| std::atoi( index.c_str() ) == 0
			|| std::atoi( index.c_str() ) > (*pbk).getRegistered() + 1 )
		{
			valid = " valid ";
			continue;
		}
		else
		{
			i = std::atoi( index.c_str() ) - 1;
			break;
		}
	}
	return i;
}

std::string	format( std::string string ) {
	std::string	formated;

	formated = string;
	if ( string.size() >= 10 )
		formated = string.substr( 0, 9 ).append( 1, '.' );
	else
	{
		while ( formated.size() != 10 )
			formated = formated.insert( 0, " " );
	}
	return formated;
}

std::string to_string98( int i ) {
	std::stringstream ss;
	ss << i;
	return ss.str();
}

void	printAllContacts( PhoneBook *pbk )
{
	int	i;

	std::cout << "⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻";
	std::cout << std::endl;
	std::cout << "|Index     |First name|Last name |Nickname  |";
	std::cout << std::endl;
	std::cout << "============================================";
	std::cout << std::endl;
	i = -1;
	while ( ++i <= (*pbk).getRegistered() )
	{
		std::cout << "|";
		std::cout << format( to_string98(i + 1) ) << "|";
		std::cout << format( (*pbk).getContacts()[i].getFirstName() ) << "|";
		std::cout << format( (*pbk).getContacts()[i].getLastName() ) << "|";
		std::cout << format( (*pbk).getContacts()[i].getNickname() ) << "|";
		std::cout << std::endl;
	}
	std::cout << "⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻";
	std::cout << std::endl;
	return;
}

void	search( PhoneBook *pbk )
{
	static std::string	cat[5] = {
		"First name: ",
		"Last name: ",
		"Nickname: ",
		"Phone number: ",
		"Dark secret: "};
	int					i;

	printAllContacts( pbk );
	i = getContactIndex( pbk );
	if ( i == -1 )
		return;
	std::cout << cat[0] << (*pbk).getContacts()[i].getFirstName() << std::endl;
	std::cout << cat[1] << (*pbk).getContacts()[i].getLastName() << std::endl;
	std::cout << cat[2] << (*pbk).getContacts()[i].getNickname() << std::endl;
	std::cout << cat[3] << (*pbk).getContacts()[i].getPhoneNumber() << std::endl;
	std::cout << cat[4] << (*pbk).getContacts()[i].getDarkSecret() << std::endl;
	std::cout << std::endl;
	return;
}
