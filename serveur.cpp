//
//  serveur.cpp
//  serveur
//
//  Created by remy DEME on 25/01/2018.
//  Copyright © 2018 remy DEME. All rights reserved.
//

#include "serveur.hpp"
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <exception>
#include <sys/socket.h>
#include <unistd.h>
#include <thread>
#include <cerrno>
#include <signal.h>

TCPServeur::TCPServeur(std::string ip, std::string port) : socket_(ip, port)
{
    sa_.sa_handler = sigchld_handler; // reap all dead processes
    if (sigemptyset(&sa_.sa_mask) == -1)
    {
        perror("Sigemptyset :");
        std::runtime_error(std::to_string(errno));
    }
    sa_.sa_flags = SA_RESTART;
    if (sigaction(SIGCHLD, &sa_, NULL) == -1)
    {
        perror("sigaction");
        std::runtime_error(std::to_string(errno));
        
    }
}


void TCPServeur::error_listen(int status)
{
    switch (status)
    {
        case EADDRINUSE:
            std::runtime_error(EADDRINUSE_ERROR);
            break;
            
        case EBADF:
            
            std::runtime_error(EBADF_ERROR);
            
            break;
        case ENOTSOCK:
            
            std::runtime_error(ENOTSOCK_ERROR);
            
            break;
        case EOPNOTSUPP:
            
            std::runtime_error(EOPNOTSUPP_ERROR);
            
            break;
            
        default:
            
            std::runtime_error(UNDEFINED_LISTEN_ERROR);
            
            ;
    }
}


const struct sockaddr_storage& TCPServeur::clientInfo() const noexcept
{
    return client_;
}


int TCPServeur::clientFd() const noexcept 
{
    return client_fd_;
}

void TCPServeur::TCPlisten()
{
    int status = 0;
    if ((status = listen(socket_, BACKLOG))== -1)
    {
        error_listen(errno);
    }
}


void sigchld_handler(int signum)
{
    signum = 2;
    int error_save = errno;
    
    while (waitpid(-1,NULL, WNOHANG) > 0);
    
    errno = error_save;
}



void TCPServeur::TCPaccept()
{
    while (true)
    {
        sockaddr_storage_size_ = sizeof(struct sockaddr_storage);
        client_fd_ = accept(socket_, (struct sockaddr*)&client_, &sockaddr_storage_size_);
        std::cout << "File descriptor : " <<  client_fd_;
    }
}


void TCPServeur::treat_client(int socket)
{
  close (socket);
  std::string message;
  received(message);
  std::cout<< "Message reçu " << message << "\n";
}

void TCPServeur::sendTo (std::string& message)
{
    static ssize_t len_message_send; // message len 
    static ssize_t len_size_send;
    
    // initialise size to zero 
    len_message_send = 0;
    len_size_send = 0;
    
    // We pass to big-endianess format the size of the message  
    static short expected_len;
    expected_len = htons(message.size()); // len of the size
    
    // send the size of the message 
    len_size_send = send(client_fd_, reinterpret_cast<const char*>(&expected_len), sizeof (expected_len), 0);
    // send the message 
    len_size_send = send(client_fd_, message.c_str(), message.size(), 0);
    
    // check if the size of the data that we have send is the same as the message
    if ( len_message_send != long(message.size()) || len_message_send == -1)
    {
        perror(" Error send : ");
        std::runtime_error(std::to_string(errno));
    }
}


void TCPServeur::received(std::string& message)
{
    static short expected_message_size;
    ssize_t len_size_received = recv(client_fd_, &expected_message_size, sizeof (expected_message_size), 0);
    
    if (len_size_received <= ERROR_FAILED)
    {
        perror ("received ");
        std::runtime_error(std::string("Error received :") + std::to_string(errno));
    }
    else
    {
        // get the size expeted anc converts it from netwprk to host 
        ssize_t len_expected = static_cast<ssize_t>(ntohs(len_size_received));
        int len_message = 0;
        char buffer[BUFFER_SIZE] = {0};
        ssize_t len_message_received = recv(client_fd_, buffer, BUFFER_SIZE, 0);
        do
        {
            len_message += len_message_received;
            message += buffer;
        } while (len_message != len_expected && len_message_received != -1);
       
       // check if something bas happened 
        if (len_message_received == ERROR_FAILED)
        {
            perror("Recv error : ");
            std::runtime_error(std::string("Error Recv length error") + std::to_string(errno));
        }
    }
}

void TCPServeur::closeClientFd()
{
    close(client_fd_);
}

void TCPServeur::closeServeurFd()
{
    close(socket_);
}

