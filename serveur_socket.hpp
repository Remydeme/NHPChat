//
//  socket.hpp
//  serveur
//
//  Created by remy DEME on 26/01/2018.
//  Copyright © 2018 remy DEME. All rights reserved.
//

#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include "socket.hpp"

class SSocket : public Socket
{
    public:
    
    SSocket(std::string ip, std::string port);
    SSocket(SSocket& ) = delete;
    SSocket(SSocket&& ) = delete;
    SSocket& operator = (SSocket& ) = delete;
    SSocket& operator = (SSocket&& ) = delete;

};
