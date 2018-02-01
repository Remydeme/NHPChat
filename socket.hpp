//
//  socket.hpp
//  serveur
//
//  Created by remy DEME on 27/01/2018.
//  Copyright © 2018 remy DEME. All rights reserved.
//

#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string>

class Socket
{
    public:
    
        Socket() = default;
        
        virtual ~Socket() = default;
    
    public :
    
    
        operator int ();
    
        struct sockaddr* addr_get() const;
    
        int addrLen_get() const;
    
    protected :
    
        void addrinfo_set() noexcept;
    
    protected :
    
        void error_socket();
    
        void error_socketOption(int status);
    
    protected :
    
        /*
         contains the return value of getaddrinfo function
        */
        int status_;
        /*
         \brief contains information about the serveur
         */
        struct addrinfo configInfo_;
        /*
        \brief pointer that point on the head of the linked list
         */
        struct addrinfo * addrList_;
    
        /*
        \brief struct addrinfo* it's a a pointer on a linked list that have been filled by the getaddrinfo function it contains a list of struct addrinfo
         */
        struct addrinfo * servInfo_;
    
        /*
         \brief socket file descriptor
         */
        int sockfd_;
    
        /*
         save the value of errno after each call of the function socket
         */
        int errno_save_;
};
