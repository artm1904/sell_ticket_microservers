#pragma once

#include <string>

#include "oatpp/macro/codegen.hpp"
#include "oatpp/macro/component.hpp"
#include "oatpp/web/server/api/ApiController.hpp"
#include "service.h"  // Подключаем сервис

#include OATPP_CODEGEN_BEGIN(ApiController)  // Начало генерации кода

class GatewayController : public oatpp::web::server::api::ApiController {
   public:
    // Конструктор принимает Service - DI
    GatewayController(const std::shared_ptr<GatewayService>& service,
                      const std::shared_ptr<ObjectMapper>& objectMapper)
        : oatpp::web::server::api::ApiController(objectMapper)  // Передаем mapper родителю
          ,
          m_service(service),
          m_objectMapper(objectMapper) {}

    // Фабричный метод для удобства
    static std::shared_ptr<GatewayController> createShared(
        const std::shared_ptr<GatewayService>& service,
        const std::shared_ptr<ObjectMapper>& objectMapper = nullptr)  // Mapper может быть default
    {
        return std::make_shared<GatewayController>(service, objectMapper);
    }

    ENDPOINT("GET", "/gateway", root) {
        OATPP_LOGi("Gateway", "GET request to /gateway");
        auto msg = m_service->getWelcomeMessage();

        OATPP_LOGi("Gateway", "Response " + std::string(msg->c_str()));
        return createResponse(Status::CODE_200, msg);
    }

    ENDPOINT("GET", "/gateway/help", help) {
        OATPP_LOGi("Gateway", "GET request to /gateway/help");
        auto helpText = m_service->getHelpText();
        OATPP_LOGi("Gateway", "Response " + std::string(helpText->c_str()));
        return createResponse(Status::CODE_200, helpText);
    }

    ENDPOINT("GET", "/gateway/health", health) {
        OATPP_LOGi("Gateway", "GET request to /gateway/health");
        auto dto = m_service->getHealth();
        // 1. Сериализуем (writeToString возвращает oatpp::String)
        auto json = m_objectMapper->writeToString(dto);

        std::string json_str = json->c_str();

        OATPP_LOGi("Gateway", "Response " + json_str);
        return createDtoResponse(Status::CODE_200, dto);
    }

   private:
    std::shared_ptr<GatewayService> m_service;
    std::shared_ptr<ObjectMapper> m_objectMapper;
};

#include OATPP_CODEGEN_END(ApiController)  // Конец генерации кода
