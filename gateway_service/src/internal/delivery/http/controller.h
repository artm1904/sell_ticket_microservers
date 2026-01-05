#pragma once

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
          m_service(service) {}

    // Фабричный метод для удобства
    static std::shared_ptr<GatewayController> createShared(
        const std::shared_ptr<GatewayService>& service,
        const std::shared_ptr<ObjectMapper>& objectMapper = nullptr)  // Mapper может быть default
    {
        return std::make_shared<GatewayController>(service, objectMapper);
    }

    ENDPOINT("GET", "/gateway", root) {
        auto msg = m_service->getWelcomeMessage();
        return createResponse(Status::CODE_200, msg);
    }

    ENDPOINT("GET", "/gateway/help", help) {
        return createResponse(Status::CODE_200, m_service->getHelpText());
    }

    ENDPOINT("GET", "/gateway/health", health) {
        auto dto = m_service->getHealth();
        return createDtoResponse(Status::CODE_200, dto);
    }

   private:
    std::shared_ptr<GatewayService> m_service;
};

#include OATPP_CODEGEN_END(ApiController)  // Конец генерации кода


