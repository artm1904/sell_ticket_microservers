#include "../../../env.h"
#include "oatpp-swagger/Model.hpp"
#include "oatpp-swagger/Resources.hpp"
#include "oatpp/macro/component.hpp"

class SwaggerComponent {
   public:
    /**
     *  General API docs info
     */
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::DocumentInfo>, swaggerDocumentInfo)([] {
        oatpp::swagger::DocumentInfo::Builder builder;

        builder.setTitle("artm1904 test API")
            .setDescription("API Gateway for microservices")
            .setVersion("1.0.0")
            .setContactName("artm1904")
            .setContactUrl("https://empty.com/")

            .addServer("http://localhost:" HTTP_PORT,
                       "Local Development Server");  // TODO: Use Config for port

        return builder.build();
    }());

    /**
     *  Swagger-Ui Resources (<oatpp-examples>/lib/oatpp-swagger/res)
     */
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::Resources>, swaggerResources)([] {
        // Make sure to specify correct full path to oatpp-swagger/res folder inside your project
        // Or set it via OATPP_SWAGGER_RES_PATH definition
        // For now we use the default embedded resources if available, or assume standard install
        // Since we use CPM, resources might need to be explicitly loaded or we rely on default
        // behavior
        return oatpp::swagger::Resources::loadResources(OATPP_SWAGGER_RES_PATH);
    }());
};
