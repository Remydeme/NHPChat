//
//  socket.cpp
//  serveur
//
//  Created by remy DEME on 26/01/2018.
//  Copyright © 2018 remy DEME. All rights reserved.
//

#include <cstring>
#include <cerrno>
#include <stdexcept>
#include <exception>
#include <iostream>
#include <unistd.h>
#include "serveur_environment.h"
#include "serveur_socket.hpp"


SSocket::SSocket(std::string ip, std::string port)
{
    /* Set the struct addrinfo */
    addrinfo_set();
    
    bool binded = false;
    
    /* nullptr replace the address IP because we use the AI_PASSIVE macro so we don't need to set the IP addresse */
    
    if (!(status_ = getaddrinfo(ip.c_str(), port.c_str(), &configInfo_, &addrList_)))
    {
        for (servInfo_ = addrList_; (servInfo_ != nullptr && !binded) ; servInfo_ = servInfo_->ai_next)
        {
           sockfd_ = socket(servInfo_->ai_family, servInfo_->ai_socktype, servInfo_->ai_protocol);
            errno_save_ = errno;
            if (sockfd_ == - 1)
            {
                perror("Creation of socket failed : ");
                continue;
            }
            
            int yes = 1;
            if (setsockopt(sockfd_,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof yes) == -1) {
                error_socketOption(errno);
            }
            
            int ret = bind(sockfd_, servInfo_->ai_addr, servInfo_->ai_addrlen);
            
            if (ret == - 1)
            {
                perror("Failed to bind :");
                close(sockfd_);
                continue;
            }
            binded = true;
        }
        
        freeaddrinfo(addrList_);
        
        if (!servInfo_)
        {
            // throw an exception for the corresponding issue
            error_socket();
        }
    
    }
    else
    {
        std::runtime_error(gai_strerror(status_));
        /* que faire si le serveur n'a pas été lancé */
    }
}



