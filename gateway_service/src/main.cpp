#include <iostream>

#include "oatpp/Environment.hpp"
#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp/web/server/HttpConnectionHandler.hpp"

void run() {
    /* Register Components in scope of run() method */
    /* Check out the "Component" pattern in Oat++ */

    // We will implement components later
    std::cout << "Gateway Service is starting..." << std::endl;
}

int main() {
    oatpp::Environment::init();

    run();

    oatpp::Environment::destroy();
    return 0;
}
