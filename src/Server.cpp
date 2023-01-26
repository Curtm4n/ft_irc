/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:49:50 by cdapurif          #+#    #+#             */
/*   Updated: 2023/01/26 15:55:05 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"

Server::Server() : hint(), sockfd(-1), clientfd(-1), readBytes(0), on(1), off(0), buffer()
{
    sockfd = socket(PF_INET6, SOCK_STREAM, 0); // IPv6 socket handle both IPv6 and IPv4 connections
    if (sockfd == -1)
        throw Server::ServerException("Cannot create a socket");
}

Server::Server(const Server& other)
{
    (void)other;

    std::cout << "Server copy constructor" << std::endl;
}

Server& Server::operator=(const Server& other)
{
    std::cout << "Server assignement operator" << std::endl;

    if (this != &other)
    {
        std::cout << "two different instances indeed" << std::endl;
    }
    return (*this);
}

Server::~Server()
{
    if (sockfd != -1)
        close(sockfd);
    if (clientfd != -1)
        close(clientfd);
}

void    Server::initServ(int port)
{
    // allow the local address to be reused when the server is restarted before the required wait time expires
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) == -1)
        throw Server::ServerException("setsockopt SO_REUSEADDR failed");

    // deactivate option IPV6_V6ONLY
    if (setsockopt(sockfd, IPPROTO_IPV6, IPV6_V6ONLY, &off, sizeof(off)) == -1)
        throw Server::ServerException("setsockopt IPV6_V6ONLY failed");

    // bind the ip address and port to a socket
    memset(&hint, 0, sizeof(hint));
    hint.sin6_family = AF_INET6;
    hint.sin6_port = htons(port);
    hint.sin6_addr = in6addr_any;
    if (bind(sockfd, (sockaddr *)&hint, sizeof(hint)) == -1)
        throw Server::ServerException("Can't bind socket");

    // mark the socket as listening for incoming connections requests
    if (listen(sockfd, SOMAXCONN) == -1)
        throw Server::ServerException("Error while listening");
}

void    Server::startServ(void)
{
    // accept a new connection on a socket
    clientfd = accept(sockfd, 0, 0);
    if (clientfd == -1)
        throw Server::ServerException("Error with accept()");

    // reading part
    while (true)
    {
        readBytes = recv(clientfd, buffer, BUFFER_SIZE, 0);

        if (readBytes == -1)
            throw Server::ServerException("Error while reading");

        if (readBytes == 0)
        {
            std::cout << "Client disconnected" << std::endl;
            break ;
        }

        buffer[readBytes] = '\0';
        std::cout << buffer;
    }
}

Server::ServerException::ServerException(const char *str) : errorMsg(str)   {}

Server::ServerException::~ServerException(void) throw() {}

const char  *Server::ServerException::what(void) const throw()
{
    return (errorMsg.c_str());
}