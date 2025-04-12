/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <drhaouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:17:03 by drhaouha          #+#    #+#             */
/*   Updated: 2025/04/10 10:46:15 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void ) {
	// std::cout << "Contact constructor called" << std::endl;
	return;
}

Contact::~Contact( void ) {
	// std::cout << "Contact destructor called" << std::endl;
	return;
}

void Contact::setContact( std::string values[] ) {
	this->_first_name = values[0];
	this->_last_name = values[1];
	this->_nickname = values[2];
	this->_phone_number = values[3];
	this->_dark_secret = values[4];
	return;
}

std::string Contact::getFirstName( void ) const {
	return this->_first_name;
}

std::string Contact::getLastName( void ) const {
	return this->_last_name;
}

std::string Contact::getNickname( void ) const {
	return this->_nickname;
}

std::string Contact::getPhoneNumber( void ) const {
	return this->_phone_number;
}

std::string Contact::getDarkSecret( void ) const {
	return this->_dark_secret;
}