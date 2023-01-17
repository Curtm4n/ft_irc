/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_irc.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:38:03 by cdapurif          #+#    #+#             */
/*   Updated: 2023/01/17 18:23:50 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"

void    init_serv(char **av)
{
    //Server          serv; // Useless, need to initiate socket creation and closing (constructor/destructor) and most of the features to handle itself
    sockaddr_in6    hint;
    int             sockfd;
    int             port;
    int             on = 1;
    
    std::cout << "Port: " << av[0] << " | Password: " << av[1] << std::endl;

    port = atoi(av[0]);
    if (!(port > 0 && port < 65536))
    {
        std::cerr << "Invalid port number or argument" << std::endl;
        return ;
    }

    // create a socket
    sockfd = socket(AF_INET6, SOCK_STREAM, 0); // ipv4 connections can be handle by ipv6 socket
    if (sockfd == -1)
    {
        std::cerr << "Can't create a socket" << std::endl;
        return ;
    }

    // allow the local address to be reused when the server is restarted before the required wait time expires
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) == -1)
    {
        close (sockfd);
        std::cerr << "setsockopt failed" << std::endl;
        return ;
    }

    // bind the ip address and port to a socket
    memset(&hint, 0, sizeof(hint));
    hint.sin6_family = AF_INET6;
    hint.sin6_port = htons(port);
    hint.sin6_addr = in6addr_any;
    if (bind(sockfd, (sockaddr *)&hint, sizeof(hint)) == -1)
    {
        close (sockfd);
        std::cerr << "Can't bind socket" << std::endl;
        return ;
    }

    // mark the socket as listening for incoming connections requests
    if (listen(sockfd, 10) == -1)
    {
        close (sockfd);
        std::cerr << "Error while listening" << std::endl;
        return ;
    }

    close(sockfd);
}

int main(int ac, char **av)
{
    if (ac != 3)
    {
        std::cerr << "Error" << std::endl << "usage: ./ircserv <port> <password>" << std::endl;
        return (EXIT_FAILURE);
    }
    init_serv(++av);

    return (EXIT_SUCCESS);
}