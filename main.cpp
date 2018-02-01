//
//  main.cpp
//  serveur
//
//  Created by remy DEME on 25/01/2018.
//  Copyright © 2018 remy DEME. All rights reserved.
//

#include <iostream>
#include "serveur.hpp"
#include <thread>
#include <chrono>

int main(int argc, const char * argv[]) {
    TCPServeur s("127.0.0.1");
    s.TCPlisten();
    s.TCPaccept();
    return 0;
}
