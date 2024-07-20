#include "json_parser_visitor.h"
#include "ajson.h"

namespace ajson {

antlrcpp::Any JSONParseVisitor::visitJson(JSONParser::JsonContext *ctx) {
  if (ctx->STRING()) {
    auto str = ctx->STRING()->getText();
    return std::make_shared<JSON>(str.substr(1, str.size() - 2));
  }
  if (ctx->NUMBER()) {
    return std::make_shared<JSON>(std::stod(ctx->NUMBER()->getText()));
  }
  if (ctx->object()) {
    return visitObject(ctx->object());
  }
  if (ctx->array()) {
    return visitArray(ctx->array());
  }
  if (ctx->getText() == "true") {
    return std::make_shared<JSON>(true);
  }
  if (ctx->getText() == "false") {
    return std::make_shared<JSON>(false);
  }
  if (ctx->getText() == "null") {
    return std::make_shared<JSON>();
  }
  throw std::logic_error("Unknown JSON value type");
}

antlrcpp::Any JSONParseVisitor::visitObject(JSONParser::ObjectContext *ctx) {
  JSONObject object;
  for (auto member : ctx->member()) {
    auto key = member->STRING()->getText();
    object[key.substr(1, key.size() - 2)] =
        visitJson(member->json()).as<std::shared_ptr<JSON>>();
  }
  return std::make_shared<JSON>(std::move(object));
}

antlrcpp::Any JSONParseVisitor::visitArray(JSONParser::ArrayContext *ctx) {
  JSONArray array;
  for (auto value : ctx->json()) {
    array.push_back(visitJson(value).as<std::shared_ptr<JSON>>());
  }
  return std::make_shared<JSON>(std::move(array));
}

} // namespace ajson
