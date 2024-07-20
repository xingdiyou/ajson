
// Generated from antlr/JSON.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "JSONVisitor.h"


namespace ajson {

/**
 * This class provides an empty implementation of JSONVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  JSONBaseVisitor : public JSONVisitor {
public:

  virtual antlrcpp::Any visitJson(JSONParser::JsonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitObject(JSONParser::ObjectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMember(JSONParser::MemberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArray(JSONParser::ArrayContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace ajson
