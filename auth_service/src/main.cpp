#include <iostream>

#include "oatpp/Environment.hpp"

void run() { std::cout << "Auth Service is starting..." << std::endl; }

int main() {
    oatpp::Environment::init();

    run();

    oatpp::Environment::destroy();
    return 0;
}
