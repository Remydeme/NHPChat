//
//  serveur.hpp
//  serveur
//
//  Created by remy DEME on 25/01/2018.
//  Copyright © 2018 remy DEME. All rights reserved.
//




#pragma once

#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string>
#include "serveur_environment.h"
#include "serveur_socket.hpp"


void sigchld_handler(int );

class TCPServeur
{
  
    public :
    
        TCPServeur(std::string ip = LOCAL_IP(), std::string port = LOCAL_PORT());
    
        /*
         delete copy constructor
         */
    
        TCPServeur(TCPServeur& ) = delete;
    
        TCPServeur(TCPServeur&& ) = delete;
    
        TCPServeur& operator = (TCPServeur& ) = delete;
    
        TCPServeur& operator =(TCPServeur&& ) =delete;
    
    public:
    
        void TCPaccept();
    
        void TCPlisten();
    
        void sendTo(std::string& );
    
        void received(std::string& );
    
        void closeClientFd();
    
        void closeServeurFd();

        void treat_client(int socket);
    
        int clientFd() const noexcept;
    
        const struct sockaddr_storage& clientInfo() const noexcept;
    
    private :
    
    void error_listen(int status);
    
    void error_bind();
    
    private :
    
        SSocket socket_;
        struct sockaddr_storage client_;
        struct sigaction sa_;
        socklen_t sockaddr_storage_size_;
        int client_fd_;
        int status_;
   
};
