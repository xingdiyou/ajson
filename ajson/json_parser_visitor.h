#pragma once

#include "antlr/JSONBaseVisitor.h"

namespace ajson {

class JSONParseVisitor : public JSONBaseVisitor {
public:
  antlrcpp::Any visitJson(JSONParser::JsonContext *ctx) override;

  antlrcpp::Any visitObject(JSONParser::ObjectContext *ctx) override;

  antlrcpp::Any visitArray(JSONParser::ArrayContext *ctx) override;
};

} // namespace ajson
