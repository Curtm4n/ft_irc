/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_irc.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:38:03 by cdapurif          #+#    #+#             */
/*   Updated: 2023/01/17 11:08:48 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"

void    init_serv(char **av)
{
    Server      serv; // Useless, need to initiate socket creation (maybe implement most of the features to handle itself)
    sockaddr_in hint;
    int         sockfd;
    int         port;
    
    std::cout << "Port: " << av[0] << " | Password: " << av[1] << std::endl;

    // Check validity of port argument
    port = atoi(av[0]);
    if (!(port > 0 && port < 65536))
    {
        std::cerr << "Invalid port number or argument" << std::endl;
        return ;
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        std::cerr << "Can't create a socket" << std::endl;
        return ;
    }

    // Bind the ip address and port to a socket
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    hint.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sockfd, (sockaddr *)&hint, sizeof(hint)) == -1)
    {
        close (sockfd);
        std::cerr << "Can't bind socket" << std::endl;
        return ;
    }
    close(sockfd);
}

int main(int ac, char **av)
{
    if (ac != 3)
    {
        std::cerr << "Error" << std::endl << "usage: ./ircserv <port> <password>" << std::endl;
        return (1);
    }
    init_serv(++av);

    return (0);
}