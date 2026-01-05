#pragma once

#include "oatpp/Types.hpp"
#include "oatpp/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class HealthDto : public oatpp::DTO {
    DTO_INIT(HealthDto, DTO)

    DTO_FIELD(String, status);
    DTO_FIELD(String, version);
    DTO_FIELD(Int64, timestamp);  // Unix timestamp
    DTO_FIELD(String, timestamp_str);  // Human-readable timestamp
};



#include OATPP_CODEGEN_END(DTO)
