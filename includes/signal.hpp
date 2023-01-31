/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:29:49 by cdapurif          #+#    #+#             */
/*   Updated: 2023/01/31 17:02:40 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HPP
# define SIGNAL_HPP

#include <signal.h>
#include <exception>

void    sighandler(int signum);

class SignalInt : public std::exception
{
    public:

        virtual const char	*what(void) const throw();
};

#endif