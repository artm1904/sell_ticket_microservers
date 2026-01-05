# Gateway Service Walkthrough
## Overview
We have successfully implemented the initial skeleton of the Gateway Service using Oat++ 1.4.0 (master branch). The service accepts HTTP requests and provides a help endpoint.

## Changes & Fixes
During development, we encountered and resolved several issues related to Oat++ version 1.4.0 API changes:

### 1. Header Locations and Namespace
Issue: `oatpp/core/macro/codegen.hpp` and `oatpp/parser/json/mapping/ObjectMapper.hpp` were moved/renamed.
Fix: Updated includes to:
```
#include "oatpp/macro/codegen.hpp"
#include "oatpp/json/ObjectMapper.hpp"
```
Namespace: Updated `oatpp::parser::json::mapping::ObjectMapper` to `oatpp::json::ObjectMapper`.

### 2. Controller Registration
Issue: `addEndpointsToRouter` is no longer available in 
`ApiController`.
Fix: Switched to `router->addController(gatewayController)` in 
`main.cpp`.

### 3. Usage of OATPP_COMPONENT
Issue: Runtime crash due to recursive component dependency simulation in 
`GatewayService`.
Fix: Removed `OATPP_COMPONENT` macro from `GatewayService` as we are using manual dependency injection in `main.cpp`.