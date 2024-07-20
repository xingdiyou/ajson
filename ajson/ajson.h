#pragma once

#include <istream>
#include <map>
#include <memory>
#include <string>
#include <variant>
#include <vector>

namespace ajson {

class JSON;

using JSONArray = std::vector<std::shared_ptr<JSON>>;
using JSONObject = std::map<std::string, std::shared_ptr<JSON>>;

class JSON {
public:
  static std::shared_ptr<JSON> Parse(const std::string &str);
  static std::shared_ptr<JSON> Parse(std::istream &is);

  JSON();
  JSON(bool value);
  JSON(double value);
  JSON(const std::string &value);
  JSON(const JSONArray &value);
  JSON(const JSONObject &value);
  JSON(std::string &&value);
  JSON(JSONArray &&value);
  JSON(JSONObject &&value);

  JSON &operator=(bool value);
  JSON &operator=(double value);
  JSON &operator=(const std::string &value);
  JSON &operator=(const JSONArray &value);
  JSON &operator=(const JSONObject &value);
  JSON &operator=(std::string &&value);
  JSON &operator=(JSONArray &&value);
  JSON &operator=(JSONObject &&value);

  bool IsNull() const;
  bool IsBool() const;
  bool IsNumber() const;
  bool IsString() const;
  bool IsArray() const;
  bool IsObject() const;

  bool &AsBool();
  double &AsNumber();
  std::string &AsString();
  JSONArray &AsArray();
  JSONObject &AsObject();
  const bool &AsBool() const;
  const double &AsNumber() const;
  const std::string &AsString() const;
  const JSONArray &AsArray() const;
  const JSONObject &AsObject() const;

  std::string Dump() const;

private:
  std::variant<std::monostate, bool, std::string, double, JSONArray, JSONObject>
      value_;
};

} // namespace ajson
