/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <drhaouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:17:14 by drhaouha          #+#    #+#             */
/*   Updated: 2025/04/16 03:59:48 by drhaouha         ###   ########.fr       */
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
	pos = str.find_first_not_of( ALPHA NUMBER SPEC );
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
		"dark secret"};
	std::string			values[5];
	std::string			valid;
	int					i;
	int					type;

	valid.clear();
	i = 0;
	while ( true ) {
		std::cout << "Enter a " << valid << cat[i] << ":" << std::endl;
		valid.clear();
		std::getline( std::cin, values[i] );
		type = ( i < 3 ) ? NAME : ( i == 3 ? PHONE : SECRET );
		if ( !isEntryValid( values[i], type ) ) {
			valid = "valid ";
			continue;
		}
		i += ( values[i].length() > 0 );
		if ( i == 5 )
			break;
	}
	(*pbk).addContact( values );
}
