/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:25:12 by cdapurif          #+#    #+#             */
/*   Updated: 2023/01/31 17:03:33 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/signal.hpp"

void    sighandler(int signum)
{
    (void)signum; //useless unless we wish to handle other signals differently
    
    throw SignalInt();
}

const char  *SignalInt::what(void) const throw()
{
    return ("fin du serveur, deconnexion des differents clients...");
}