/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:49:50 by cdapurif          #+#    #+#             */
/*   Updated: 2023/01/16 18:56:38 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"

Server::Server()
{
    std::cout << "Server default constructor" << std::endl;
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
    std::cout << "Server destructor" << std::endl; 
}