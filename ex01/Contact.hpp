/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <drhaouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:17:09 by drhaouha          #+#    #+#             */
/*   Updated: 2025/04/10 10:44:56 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

class Contact {

private:
	
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _dark_secret;

public:

	Contact( void );
	~Contact( void );
	void 		setContact( std::string values[] );
	std::string getFirstName( void ) const;
	std::string getLastName( void ) const;
	std::string getNickname( void ) const;
	std::string getPhoneNumber( void ) const;
	std::string getDarkSecret( void ) const;

};

#endif