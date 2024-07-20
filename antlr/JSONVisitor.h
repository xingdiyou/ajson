
// Generated from antlr/JSON.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "JSONParser.h"


namespace ajson {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by JSONParser.
 */
class  JSONVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by JSONParser.
   */
    virtual antlrcpp::Any visitJson(JSONParser::JsonContext *context) = 0;

    virtual antlrcpp::Any visitObject(JSONParser::ObjectContext *context) = 0;

    virtual antlrcpp::Any visitMember(JSONParser::MemberContext *context) = 0;

    virtual antlrcpp::Any visitArray(JSONParser::ArrayContext *context) = 0;


};

}  // namespace ajson
