#include <iostream>

#include "env.h"  // настройки
#include "internal/delivery/http/controller.h"
#include "internal/delivery/http/service.h"
#include "oatpp/Environment.hpp"
#include "oatpp/json/ObjectMapper.hpp"
#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp/web/server/HttpConnectionHandler.hpp"

void run() {
    /* Register Components in scope of run() method */
    /* Check out the "Component" pattern in Oat++ */

    /* 1. Создаем компоненты (DI) */

    // ObjectMapper для JSON
    auto objectMapper = std::make_shared<oatpp::json::ObjectMapper>();

    // Сервис
    auto gatewayService = std::make_shared<GatewayService>();

    /* 2. Настройка Сети */
    // Роутер
    auto router = oatpp::web::server::HttpRouter::createShared();

    // Контроллер
    auto gatewayController = GatewayController::createShared(gatewayService, objectMapper);
    router->addController(gatewayController);

    // Обработчик соединений
    auto connectionHandler = oatpp::web::server::HttpConnectionHandler::createShared(router);

    // Провайдер (слушает порт)
    auto connectionProvider = oatpp::network::tcp::server::ConnectionProvider::createShared(
        {"0.0.0.0", static_cast<uint16_t>(std::atoi(HTTP_PORT)), oatpp::network::Address::IP_4});

    /* 3. Создаем сервер */
    oatpp::network::Server server(connectionProvider, connectionHandler);
    std::cout << "Gateway Service running on port " << HTTP_PORT << "..." << std::endl;

    // Запуск (блокирующий вызов)
    server.run();
}

int main() {
    oatpp::Environment::init();  // Инициализация Oat++
    run();
    oatpp::Environment::destroy();  // Очистка
    return 0;
}
