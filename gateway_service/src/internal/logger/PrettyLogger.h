#pragma once

#include <chrono>
#include <iomanip>
#include <iostream>

#include "ansi_colors.h"
#include "oatpp/Environment.hpp"

class PrettyLogger : public oatpp::Logger {
   public:
    void log(v_uint32 priority, const std::string& tag, const std::string& message) override {
        auto now = std::chrono::system_clock::now();
        auto now_c = std::chrono::system_clock::to_time_t(now);
        auto now_tm = *std::localtime(&now_c);

        switch (priority) {
            case PRIORITY_V:
            case PRIORITY_D:
                std::cout << RESET << GRAY << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S") << " ["
                          << tag << "] " << message << std::endl;
                break;

            case PRIORITY_I:
                std::cout << RESET << GREEN << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S") <<RESET << GRAY <<" ["
                          << tag << "] " << message << std::endl;
                break;

            case PRIORITY_W:
                std::cout << RESET << YELLOW << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S") << " ["
                          << tag << "] " << message << std::endl;
                break;

            case PRIORITY_E:
                std::cout << RESET << RED << BOLD << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S")
                          << " [" << tag << "] " << message << std::endl;
                break;

            default:
                std::cout << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S") << " [" << tag << "] "
                          << message << std::endl;
        }
    }
};
