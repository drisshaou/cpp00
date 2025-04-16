/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <drhaouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:17:14 by drhaouha          #+#    #+#             */
/*   Updated: 2025/04/16 15:35:08 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	getContactIndex( PhoneBook *pbk ) {
	std::string	valid;
	std::string	index;
	int			i;

	valid = "n ";
	i = -1;
	while ( true && (*pbk).getRegistered() != -1 ) {
		std::cout << "Enter a" << valid << "index" << ":" << std::endl;
		valid = "n ";
		std::getline( std::cin, index );
		if ( std::cin.eof() )
			break;
		if ( index.length() != 1 || !std::isdigit( index[0] )
			|| std::atoi( index.c_str() ) == 0
			|| std::atoi( index.c_str() ) > (*pbk).getRegistered() + 1 ) {
			valid = " valid ";
			continue;
		}
		else {
			i = std::atoi( index.c_str() ) - 1;
			break;
		}
	}
	return i;
}

std::string	format( std::string str ) {
	std::string	formated;

	formated = str;
	if ( str.length() >= 10 )
		formated = str.substr( 0, 9 ).append( 1, '.' );
	else {
		while ( formated.length() != 10 )
			formated = formated.insert( 0, " " );
	}
	return formated;
}

void	printAllContacts( PhoneBook *pbk ) {
	std::string	number;
	int			i;

	std::cout << "⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻" << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "=============================================" << std::endl;
	i = -1;
	while ( ++i <= (*pbk).getRegistered() ) {
		number.clear();
		number.push_back( char( i + 1 + 48 ) );
		std::cout << "|";
		std::cout << format( number ) << "|";
		std::cout << format( (*pbk).getContacts()[i].getFirstName() ) << "|";
		std::cout << format( (*pbk).getContacts()[i].getLastName() ) << "|";
		std::cout << format( (*pbk).getContacts()[i].getNickname() ) << "|";
		std::cout << std::endl;
	}
	std::cout << "⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻";
	std::cout << std::endl;
	return;
}

void	search( PhoneBook *pbk ) {
	static std::string	cat[5] = {
		"First name: ",
		"Last name: ",
		"Nickname: ",
		"Phone number: ",
		"Darkest secret: "};
	int					i;
	
	system( "clear" );
	std::cout << "Enter a command (ADD, SEARCH or EXIT):\nSEARCH" << std::endl;
	printAllContacts( pbk );
	i = getContactIndex( pbk );
	if ( i == -1 ) {
		if ( !std::cin.eof() )
			std::cout << "Phonebook empty, back to menu." << std::endl;
		return;
	}
	std::cout << cat[0] << (*pbk).getContacts()[i].getFirstName() << std::endl;
	std::cout << cat[1] << (*pbk).getContacts()[i].getLastName() << std::endl;
	std::cout << cat[2] << (*pbk).getContacts()[i].getNickname() << std::endl;
	std::cout << cat[3] << (*pbk).getContacts()[i].getPhoneNumber() << std::endl;
	std::cout << cat[4] << (*pbk).getContacts()[i].getDarkSecret() << std::endl;
	std::cout << std::endl;
	return;
}
