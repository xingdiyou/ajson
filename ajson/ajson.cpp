#include "ajson.h"
#include "antlr/JSONLexer.h"
#include "antlr/JSONParser.h"
#include "json_parser_visitor.h"
#include <utility>

namespace ajson {

std::shared_ptr<JSON> JSON::Parse(const std::string &str) {
  antlr4::ANTLRInputStream input(str);
  JSONLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  JSONParser parser(&tokens);
  JSONParseVisitor visitor;
  return visitor.visit(parser.json()).as<std::shared_ptr<JSON>>();
}

std::shared_ptr<JSON> JSON::Parse(std::istream &is) {
  antlr4::ANTLRInputStream input(is);
  JSONLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  JSONParser parser(&tokens);
  JSONParseVisitor visitor;
  return visitor.visit(parser.json()).as<std::shared_ptr<JSON>>();
}

JSON::JSON(){};

JSON::JSON(bool value) : value_(value) {}

JSON::JSON(double value) : value_(value) {}

JSON::JSON(const std::string &value) : value_(value) {}

JSON::JSON(const JSONArray &value) : value_(value) {}

JSON::JSON(const JSONObject &value) : value_(value) {}

JSON::JSON(std::string &&value) : value_(std::move(value)) {}

JSON::JSON(JSONArray &&value) : value_(std::move(value)) {}

JSON::JSON(JSONObject &&value) : value_(std::move(value)) {}

JSON &JSON::operator=(bool value) {
  value_ = value;
  return *this;
}

JSON &JSON::operator=(double value) {
  value_ = value;
  return *this;
}

JSON &JSON::operator=(const std::string &value) {
  value_ = value;
  return *this;
}

JSON &JSON::operator=(const JSONArray &value) {
  value_ = value;
  return *this;
}

JSON &JSON::operator=(const JSONObject &value) {
  value_ = value;
  return *this;
}

JSON &JSON::operator=(std::string &&value) {
  value_ = std::move(value);
  return *this;
}

JSON &JSON::operator=(JSONArray &&value) {
  value_ = std::move(value);
  return *this;
}

JSON &JSON::operator=(JSONObject &&value) {
  value_ = std::move(value);
  return *this;
}

bool JSON::IsNull() const {
  return std::holds_alternative<std::monostate>(value_);
}

bool JSON::IsBool() const { return std::holds_alternative<bool>(value_); }

bool JSON::IsNumber() const { return std::holds_alternative<double>(value_); }

bool JSON::IsString() const {
  return std::holds_alternative<std::string>(value_);
}

bool JSON::IsArray() const { return std::holds_alternative<JSONArray>(value_); }

bool JSON::IsObject() const {
  return std::holds_alternative<JSONObject>(value_);
}

bool &JSON::AsBool() { return std::get<bool>(value_); }

double &JSON::AsNumber() { return std::get<double>(value_); }

std::string &JSON::AsString() { return std::get<std::string>(value_); }

JSONArray &JSON::AsArray() { return std::get<JSONArray>(value_); }

JSONObject &JSON::AsObject() { return std::get<JSONObject>(value_); }

const bool &JSON::AsBool() const { return std::get<bool>(value_); }

const double &JSON::AsNumber() const { return std::get<double>(value_); }

const std::string &JSON::AsString() const {
  return std::get<std::string>(value_);
}

const JSONArray &JSON::AsArray() const { return std::get<JSONArray>(value_); }

const JSONObject &JSON::AsObject() const {
  return std::get<JSONObject>(value_);
}

std::string JSON::Dump() const {
  if (IsNull()) {
    return "null";
  }
  if (IsBool()) {
    return AsBool() ? "true" : "false";
  }
  if (IsNumber()) {
    return std::to_string(AsNumber());
  }
  if (IsString()) {
    return "\"" + AsString() + "\"";
  }
  if (IsArray()) {
    std::ostringstream oss;
    oss << "[";
    const JSONArray &arr = AsArray();
    bool first = true;
    for (const auto &value : arr) {
      if (!first) {
        oss << ",";
        first = false;
      }
      oss << value->Dump();
    }
    oss << "]";
    return oss.str();
  }
  if (IsObject()) {
    std::ostringstream oss;
    oss << "{";
    const JSONObject &obj = AsObject();
    bool first = true;
    for (const auto &[key, json] : obj) {
      if (!first) {
        oss << ",";
        first = false;
      }
      oss << "\"" << key << "\":" << json->Dump();
    }
    oss << "}";
    return oss.str();
  }
  throw std::logic_error("Unknown JSON value type");
}

} // namespace ajson
