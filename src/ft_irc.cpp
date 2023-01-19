/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_irc.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:38:03 by cdapurif          #+#    #+#             */
/*   Updated: 2023/01/19 17:39:00 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"

void    launchServer(char **av)
{
    Server          server;
    int             port;

    std::cout << "Port: " << av[0] << " | Password: " << av[1] << std::endl;

    port = atoi(av[0]);
    if (!(port > 0 && port < 65536))
        throw Server::ServerException("Invalid port number or argument");

    server.initServ(port);
    server.startServ();
}

int main(int ac, char **av)
{
    if (ac != 3)
    {
        std::cerr << "Error" << std::endl << "usage: ./ircserv <port> <password>" << std::endl;
        return (EXIT_FAILURE);
    }
    try
    {
        launchServer(++av);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}