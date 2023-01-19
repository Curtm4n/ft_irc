/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_irc.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:38:03 by cdapurif          #+#    #+#             */
/*   Updated: 2023/01/19 11:48:06 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"

void    init_serv(char **av)
{
    //Server          serv; // useless, need to initiate socket creation and closing (constructor/destructor) and most of the features to handle itself
    sockaddr_in6    hint;
    int             sockfd;
    int             clientfd;
    int             port;
    int             on = 1;
    int             off = 0;
    char            buffer[BUFFER_SIZE + 1];
    
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
        close(sockfd);
        std::cerr << "setsockopt SO_REUSEADDR failed" << std::endl;
        return ;
    }

    // deactivate option IPV6_V6ONLY
    if (setsockopt(sockfd, IPPROTO_IPV6, IPV6_V6ONLY, &off, sizeof(off)) == -1)
    {
        close(sockfd);
        std::cerr << "setsockopt IPV6_V6ONLY failed" << std::endl;
        return ;
    }

    // bind the ip address and port to a socket
    memset(&hint, 0, sizeof(hint));
    hint.sin6_family = AF_INET6;
    hint.sin6_port = htons(port);
    hint.sin6_addr = in6addr_any;
    if (bind(sockfd, (sockaddr *)&hint, sizeof(hint)) == -1)
    {
        close(sockfd);
        std::cerr << "Can't bind socket" << std::endl;
        return ;
    }

    // mark the socket as listening for incoming connections requests
    if (listen(sockfd, SOMAXCONN) == -1)
    {
        close(sockfd);
        std::cerr << "Error while listening" << std::endl;
        return ;
    }

    // accept a new connection on a socket
    
    clientfd = accept(sockfd, 0, 0);
    if (clientfd == -1)
    {
        close(sockfd);
        std::cerr << "Error with accept()" << std::endl;
        return ;
    }

    // reading part
    int readBytes;
    
    while (true)
    {
        //memset(buffer, 0, 100); //would fill the buffer with character 0 ('\0') but is unoptimized with large buffer_size

        readBytes = recv(clientfd, buffer, BUFFER_SIZE, 0);

        if (readBytes == -1)
        {
            close(sockfd);
            close(clientfd);
            std::cerr << "Error while reading" << std::endl;
            return ;
        }

        if (readBytes == 0)
        {
            std::cout << "Client disconnected" << std::endl;
            break ;
        }

        buffer[readBytes] = '\0';
        std::cout << buffer;
    }
    
    close(sockfd);
    close(clientfd);
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