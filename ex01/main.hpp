/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <drhaouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:05:05 by drhaouha          #+#    #+#             */
/*   Updated: 2025/04/14 12:16:48 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
#define MAIN_H

#include "PhoneBook.hpp"
#include <cstdlib>
#include <sstream>

int			getContactIndex( PhoneBook *pbk );
std::string	format( std::string string );
void		printAllContacts( PhoneBook *pbk );
void		search( PhoneBook *pbk );
bool		isPhoneNumberValid( std::string string );
void		add( PhoneBook *pbk );

#endif