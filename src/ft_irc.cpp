/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_irc.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:38:03 by cdapurif          #+#    #+#             */
/*   Updated: 2023/01/16 22:12:43 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"

void    init_serv(char **av)
{
    Server      serv; // Useless, need to initiate socket creation (maybe implement most of the features to handle itself)
    sockaddr    hint;
    int         sockfd;
    
    std::cout << "Port: " << av[0] << " | Password: " << av[1] << std::endl;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        std::cerr << "Can't create a socket, quitting program" << std::endl;
        return ;
    }

    // Bind the ip address and port to a socket
    //hint.sa_family = AF_INET;
    //hint.sa_data = 
    //(sockfd, )
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