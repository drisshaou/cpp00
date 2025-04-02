/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drhaouha <drhaouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:43:38 by drhaouha          #+#    #+#             */
/*   Updated: 2025/04/02 11:45:58 by drhaouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <cctype>

int	main(int argc, char *argv[])
{
	int		i;
	size_t	x;
	char	loud[] = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (argc == 1)
		std::cout << loud << std::endl;
	else
	{
		i = 0;
		while (++i < argc)
		{
			x = -1;
			while (++x < strlen(argv[i]))
				argv[i][x] = toupper(argv[i][x]);
			std::cout << argv[i];
		}
		std::cout << std::endl;
	}
	return (0);
}