/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <drhaouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:17:14 by drhaouha          #+#    #+#             */
/*   Updated: 2025/04/10 20:06:31 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

bool	isPhoneNumberValid( std::string string ) {
	int	i;
	int	size;

	if ( string.empty() )
		return false;
	i = -1;
	size = string.size();
	while ( ++i < size ) {
		if ( !std::isdigit( string[i] ) )
			return false;
	}
	if ( size < 10 || size > 10 || string[0] != '0' )
		return false;
	return true;
}

void	add( PhoneBook *pbk )
{
	static std::string	cat[5] = {
		"first name",
		"last name",
		"nickname",
		"phone number",
		"dark secret"};
	std::string			values[5];
	std::string			valid;
	int					i;

	valid.clear();
	i = 0;
	while ( true )
	{
		std::cout << "Enter a " << valid << cat[i] << ":" << std::endl;
		valid.clear();
		std::getline( std::cin, values[i] );
		if ( i == 3 && !isPhoneNumberValid( values[i] ) )
		{
			valid = "valid ";
			continue;
		}
		i += (values[i].size() > 0);
		if ( i == 5 )
			break;
	}
	(*pbk).addContact( values );
}
