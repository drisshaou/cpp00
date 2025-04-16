/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <drhaouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:05:05 by drhaouha          #+#    #+#             */
/*   Updated: 2025/04/16 16:11:32 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
#define MAIN_H

#define NAME			0
#define PHONE			1
#define SECRET			2
#define ALPHA			"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMBER			"0123456789"
#define	SPEC			"- !',.:;"
#define	EMPTY			"Empty string found!"
#define	FORBIDDEN		"Does not match regex!"

#define	REGEX_NAME		"[a-zA-Z]{2,50}[-]{0,1}"
#define	REGEX_PHONE		"[0]{1}[1-9]{1}[0-9]{8}"
#define	REGEX_SECRET	"[0-9a-zA-Z- !',.:;]{200}"


#include "PhoneBook.hpp"
#include <cstdlib>

int			getContactIndex( PhoneBook *pbk );
std::string	format( std::string str );
void		printAllContacts( PhoneBook *pbk );
void		search( PhoneBook *pbk );
bool		isEntryValid( std::string str, int entry );
int			countChar( std::string str, char c );
void		add( PhoneBook *pbk );

#endif