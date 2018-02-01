//
//  socket.cpp
//  serveur
//
//  Created by remy DEME on 27/01/2018.
//  Copyright © 2018 remy DEME. All rights reserved.
//

#include "socket.hpp"
#include "serveur_environment.h"
#include <cerrno>
#include <stdexcept>
#include <exception>


void Socket::error_socketOption(int status)
{
    switch(status)
    {
        case EBADF:
            
            
            std::runtime_error(EBADF_ERROR);
            
            break ;
        case EINVAL:
            
            std::runtime_error(EINVAL_OPTION_ERROR);
            
            break;
        case ENOPROTOOPT:
            
            std::runtime_error(ENOPROTOOPT_OPTION_ERROR);
            
            break;
        case ENOTSOCK:
            
            std::runtime_error(ENOTSOCK_OPTION_ERROR);
            
            break;
        case EFAULT:
            
            std::runtime_error(EFAULT_OPTION_ERROR);
            
            break;
        default:
            ;
            
    }
}

void Socket::error_socket()
{
    switch (errno_save_)
    {
        case EACCES:
            
            std::runtime_error(EACCESS_ERROR);
            
            break;
            
        case EAFNOSUPPORT:
            
            std::runtime_error(EAFNOSUPPORT_ERROR);
            
            break;
            
        case EINVAL:
            
            std::runtime_error(EINVAL_ERROR);
            
            break;
            
        case EMFILE:
            
            std::runtime_error(EMFILE_ERROR);
            
            break;
            
        case ENFILE:
            
            std::runtime_error(ENFILE_ERROR);
            
            break;
            
        case ENOBUFS:
            
            std::runtime_error(ENOBUFS_ERROR);
            
            break;
            
        case ENOMEM:
            
            std::runtime_error(ENOMEM_ERROR);
            
            break;
            
        case EPROTONOSUPPORT:
            
            std::runtime_error(EPROTONOSUPPORT_ERROR);
            
            break;
            
        default:
            std::runtime_error(UNDEFINED_ERROR);
            ;
    }
}

Socket::operator int()
{
    return sockfd_;
}


void Socket::addrinfo_set() noexcept
{
    std::memset(&configInfo_, 0, sizeof(struct addrinfo));
    /*
     let choose if it's IPV4 or IPV6
     */
    configInfo_.ai_family = AF_UNSPEC;
    /*
     use stream socket for TCP
     */
    configInfo_.ai_socktype = SOCK_STREAM;

}
