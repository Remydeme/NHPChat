//
//  serveur_environment.h
//  serveur
//
//  Created by remy DEME on 25/01/2018.
//  Copyright © 2018 remy DEME. All rights reserved.
//

#pragma once

/*
   SERVEUR CONFIG VAR
 */

#define LOCAL_IP() "127.0.0.1"
#define LOCAL_PORT() "3400"
#define BACKLOG 20
#define ERROR_FAILED -1 
#define BUFFER_SIZE 10000


/*
   ERROR MESSAGE
 */


// SSocket ERROR
#define EACCESS_ERROR "EACESS_error This kind of SSocket cannot be created."

#define EAFNOSUPPORT_ERROR " EAFNOSUPPORT_ERROR the implementation doesn't support the familly address mentionned."

#define EINVAL_ERROR "EINVAL_ERROR The protocol that has been use is unknow ."

#define EMFILE_ERROR "EMFILE_ERROR The file table is filled"

#define ENFILE_ERROR "ENFILE_ERROR The limit of file that can be opened has been reached."

#define ENOBUFS_ERROR "ENOBUFS_ERROR Not enough memory for the allocation of the buffer. The SSocket cannot be created."

#define ENOMEM_ERROR "ENOBUFS_ERROR Not enough memory for the allocation of the buffer. The SSocket cannot be created."

#define EPROTONOSUPPORT_ERROR "EPROTONOSUPPORT_ERROR The protocol is not available in this domain."

#define UNDEFINED_ERROR "UNDEFINED ERROR the creation or the binding of SSocket failed for an unknown error."


// LISTEN ERROR


#define EADDRINUSE_ERROR "AEDDRINUSE_ERROR Another SSocket is listenning on the same port."

#define EBADF_ERROR "EBADF_ERROR The SSocket file descriptor is not a good argument."

#define ENOTSOCK_ERROR "ENOTSOCK_ERROR The file desriptor doesn't refer to a SSocket."

#define EOPNOTSUPP_ERROR "EOPNOTSUPP_ERROR The SSocket is not of the type that support the listen operation."

#define UNDEFINED_LISTEN_ERROR "Undefine Error the listen operation has failed."


// define SET_SSocket OPTION ERROR

#define EBADF_OPTION_ERROR "The argument sockfd is not a valid descriptor."

#define EFAULT_OPTION_ERROR "EFAULT_ERROR The address pointed to by optval is not in a valid part of the process address space. For getsockopt(), this error may also be returned if optlen is not in a valid part of the process address space."

#define EINVAL_OPTION_ERROR "EINVAL_OPTION_ERROR optlen invalid in setsockopt(). In some cases this error can also occur for an invalid value in optval (e.g., for the IP_ADD_MEMBERSHIP option described in ip(7))."

#define ENOPROTOOPT_OPTION_ERROR "ENOPROTOOPT_OPTION_ERROR The option is unknown at the level indicated."

#define ENOTSOCK_OPTION_ERROR "ENOTSOCK_OPTION_ERROR The argument sockfd is a file, not a SSocket."




/*
    
 */
