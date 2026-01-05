#pragma once

#include <chrono>
#include "../../../env.h"
#include "dto/HealthDto.hpp"

class GatewayService {
   public:
    oatpp::String getHelpText() {
        return "Gateway Service v" NODE_VERSION "\n Available endpoints:\n"
               "\t GET /gateway/health\n"
               "\t GET /gateway/help\n"
               "\t GET /gateway/\n";
    }

    oatpp::Object<HealthDto> getHealth() {
        auto dto = HealthDto::createShared();
        dto->status = "ok";
        dto->version = NODE_VERSION;
        auto now = std::chrono::system_clock::now();
        auto duration =
            std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
        dto->timestamp = duration.count();

        auto timestamp_str = std::chrono::system_clock::to_time_t(now);
        dto->timestamp_str = std::ctime(&timestamp_str);
        return dto;
    }

    oatpp::String getWelcomeMessage() { return "Welcome to Gateway Service"; }
};
