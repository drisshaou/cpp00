/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <drhaouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:17:14 by drhaouha          #+#    #+#             */
/*   Updated: 2025/04/16 15:31:52 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main( void ) {
	PhoneBook	pbk;
	std::string	cmd;

	while (true) {
		cmd.clear();
		if ( !std::cin.eof() )
			std::cout << "Enter a command (ADD, SEARCH or EXIT):" << std::endl;
		std::getline(std::cin, cmd);
		if ( std::cin.eof() ) {
			std::cout << "Ctrl+D pressed Exiting phonebook." << std::endl;
			break;
		}
		if ( cmd == "ADD" )
			add( &pbk );
		else if ( cmd == "SEARCH" )
			search( &pbk );
		else if ( cmd == "EXIT" )
			break;
		else
			std::cout << "Command not found !" << std::endl;
	}
	return 0;
}