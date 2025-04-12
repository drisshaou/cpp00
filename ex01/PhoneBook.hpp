/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <drhaouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:17:25 by drhaouha          #+#    #+#             */
/*   Updated: 2025/04/10 02:22:07 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {

private:

	Contact	_contacts[8];
	int		_index;
	int		_registered;

public:

	PhoneBook( void );
	~PhoneBook( void );
	void 			addContact( std::string values[] );
	const Contact*	getContacts( void ) const;
	int				getIndex( void ) const;
	int				getRegistered( void ) const;

};

#endif