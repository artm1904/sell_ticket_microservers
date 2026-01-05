#pragma once

#include "oatpp/Types.hpp"

class GatewayService {
   public:
    oatpp::String getHelpText() {
        return "Gateway Service v0.1.0 \n Available endpoints:\n"
               "\t GET /gateway/health\n"
               "\t GET /gateway/";
    }

    oatpp::String getHealth() { return "OK"; }

    oatpp::String getWelcomeMessage() { return "Welcome to Gateway Service"; }
};
