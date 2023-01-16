/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_irc.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:38:03 by cdapurif          #+#    #+#             */
/*   Updated: 2023/01/16 18:55:27 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"

void    init_serv(char **av)
{
    Server  serv;
    
    std::cout << "Port: " << av[0] << " | Password: " << av[1] << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 3)
    {
        std::cout << "Error" << std::endl << "usage: ./ircserv <port> <password>" << std::endl;
        return (1);
    }
    init_serv(++av);

    return (0);
}