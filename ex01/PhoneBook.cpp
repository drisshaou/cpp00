/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <drhaouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:17:19 by drhaouha          #+#    #+#             */
/*   Updated: 2025/04/10 02:39:49 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) : _index(0), _registered(-1) {
	// std::cout << "PhoneBook constructor called" << std::endl;
	return;
}

PhoneBook::~PhoneBook( void ) {
	// std::cout << "PhoneBook destructor called" << std::endl;
	return;
}

void	PhoneBook::addContact( std::string values[] ) {
	this->_index %= 8;
	if (this->_registered < this->_index)
		this->_registered = this->_index;
	this->_contacts[this->_index++].setContact(values);
}

const Contact*	PhoneBook::getContacts( void ) const {
	return this->_contacts;
}

int	PhoneBook::getIndex( void ) const {
	return (this->_index);
}

int	PhoneBook::getRegistered( void ) const {
	return (this->_registered);
}