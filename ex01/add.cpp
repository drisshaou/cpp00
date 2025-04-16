/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <drhaouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:17:14 by drhaouha          #+#    #+#             */
/*   Updated: 2025/04/17 01:06:03 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

bool	isNameValid( std::string str ) {
	std::size_t	len;
	std::size_t	i;
	int			space_count;
	int			last_space_index;

	len = str.size();
	if ( len < 2 || len > 50 )
		return false;
	space_count = 0;
	last_space_index = -2;
	i = 0;
	while ( i < len ) {
		if ( !std::isalpha( str[i] ) && str[i] != ' ' )
			return false;
		else if ( str[i] == ' ' ) {
			if ( i < 1 || i > len - 2 || ( i > 0 && str[i - 1] == ' ' )
				|| ( (int)i - last_space_index < 2 ) )
				return false;
			last_space_index = i;
			space_count++;
			if ( space_count > 3 )
				return false;
		}
		i++;
	}
	return true;
}

bool	isPhoneValid( std::string str ) {
	std::size_t	len;
	std::size_t	i;

	len = str.size();
	if (len != 10 || str[0] != '0' || str[1] == '0')
		return false;
	i = 0;
	while ( i < len ) {
		if ( !std::isdigit( str[i] ) )
			return false;
		i++;
	}
	return true;
}

bool	isSecretValid( std::string str ) {
	std::size_t	len;
	std::size_t	i;

	len = str.size();
	if ( len < 1 || len > 200 )
		return false;
	i = 0;
	while ( i < len ) {
		if ( !std::isalnum( str[i] ) && !std::strchr( SPEC, str[i] ) )
			return false;
		i++;
	}
	return true;
}

bool	isEntryValid( std::string str, int entry ) {
	if ( str.empty() )
		return false;
	if ( entry == NAME )
		return isNameValid( str );
	else if ( entry == PHONE )
		return isPhoneValid( str );
	else if ( entry == SECRET )
		return isSecretValid( str );
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
