/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:49:50 by cdapurif          #+#    #+#             */
/*   Updated: 2023/01/17 17:29:21 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"

Server::Server()
{
    // Create the socket here, if creation fails, throw an exception (catch it in the main)
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
    // Close the socket here (if constructor throw, destructor is not run, so technically close is always safe)
    std::cout << "Server destructor" << std::endl; 
}