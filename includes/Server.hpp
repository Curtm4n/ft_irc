/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:46:52 by cdapurif          #+#    #+#             */
/*   Updated: 2023/01/31 16:30:29 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include <cstdlib>
# include <cstring>
# include <iostream>
# include <unistd.h>
# include <exception>
# include <arpa/inet.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netinet/ip.h>

# define BUFFER_SIZE 4096

class Server
{

    public:

        Server();
        Server(const Server& other);
        Server& operator=(const Server& other);

        ~Server();

        void    initServ(int port);
        void    startServ(void);

    private:

        sockaddr_in6    hint;
        int             sockfd;
        int             clientfd;
        int             readBytes;
        int             on;
        int             off;
        char            buffer[BUFFER_SIZE + 1];

    public:

        class ServerException : public std::exception
        {
            private:

                std::string errorMsg;

            public:

                ServerException(const char *msg);
                virtual const char  *what(void) const throw();

                ~ServerException() throw();
        };
};

#endif