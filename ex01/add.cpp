/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <drhaouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:17:14 by drhaouha          #+#    #+#             */
/*   Updated: 2025/04/16 16:11:22 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	countChar( std::string str, char c ) {
	std::size_t	i;
	int			count;
	
	i = 0;
	count = 0;
	while ( i < str.length() ) {
		if ( str[i] == c )
			count++;
		i++;
	}
	return count;
}

bool	isEntryValid( std::string str, int entry ) {
	std::size_t	pos;

	if ( str.empty() )
		return false;
	pos = str.find_first_not_of( ALPHA );
	if ( entry == NAME ) {
		if ( pos != std::string::npos && str.length() > 2 && str.length() <= 51 && countChar( str, '-' ) == 1 )
			return true;
		else if (pos == std::string::npos && str.length() >= 2 && str.length() <= 50 )
			return true;
		else
			return false;
	}
	pos = str.find_first_not_of( NUMBER );
	if ( entry == PHONE ) {
		if ( pos != std::string::npos || str.length() != 10 || str[0] != '0' || str[1] == '0' )
			return false;
	}
	pos = str.find_first_not_of( NUMBER ALPHA SPEC );
	if ( entry == SECRET ) {
		if ( pos != std::string::npos || str.length() > 200 )
			return false;

	}
	return true;
}

void	add( PhoneBook *pbk ) {
	static std::string	cat[5] = {
		"first name",
		"last name",
		"nickname",
		"phone number",
		"darkest secret"};
	std::string			values[5];
	int					i;
	int					type;
	std::string			valid;

	system( "clear" );
	std::cout << "Enter a command (ADD, SEARCH or EXIT):\nADD" << std::endl;
	i = 0;
	while ( true ) {
		type = ( i < 3 ) ? NAME : ( i == 3 ? PHONE : SECRET );
		std::cout << "Enter your " << cat[i] << valid << ":" << std::endl;
		valid.clear();
		std::getline( std::cin, values[i] );
		if ( std::cin.eof() )
			return;
		if ( !isEntryValid( values[i], type ) ) {
			valid = ( i < 3 ) ? REGEX_NAME : ( i == 3 ? REGEX_PHONE : REGEX_SECRET );
			valid = " (regex: " + valid + ")";
			std::cout << ( values[i].empty() ? EMPTY : FORBIDDEN ) << std::endl;
			std::cin.clear();
			continue;
		}
		i++;
		if ( i == 5 )
			break;
	}
	system( "clear" );
	(*pbk).addContact( values );
}
