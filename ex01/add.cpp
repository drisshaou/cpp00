/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <drhaouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:17:14 by drhaouha          #+#    #+#             */
/*   Updated: 2025/04/16 04:58:15 by drhaouha         ###   ########.fr       */
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
	std::size_t	length;

	if ( str.empty() )
		return false;
	pos = str.find_first_not_of( ALPHA );
	if ( ( pos != std::string::npos || countChar( str, '-' ) > 1 )
		&& entry == NAME )
		return false;
	pos = str.find_first_not_of( NUMBER );
	if ( pos != std::string::npos && entry == PHONE )
		return false;
	pos = str.find_first_not_of( NUMBER ALPHA SPEC );
	if ( pos != std::string::npos && entry == SECRET )
		return false;
	length = str.length();
	if ( ( length < 10 || length > 10 || str[0] != '0' ) && entry == PHONE )
		return false;
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

	i = 0;
	while ( true ) {
		type = ( i < 3 ) ? NAME : ( i == 3 ? PHONE : SECRET );
		std::cout << "Enter your " << cat[i] << valid << ":" << std::endl;
		valid.clear();
		std::getline( std::cin, values[i] );
		if ( !isEntryValid( values[i], type ) ) {
			valid = ( i < 3 ) ? "[a-zA-Z|-]" : ( i == 3 ? "[0-9]" : "[0-9|a-zA-Z|- !',.:;]" );
			valid = " (valid chars: " + valid + ")";
			std::cout << ( values[i].empty() ? EMPTY : FORBIDDEN ) << std::endl;
			continue;
		}
		i++;
		if ( i == 5 )
			break;
	}
	(*pbk).addContact( values );
}
