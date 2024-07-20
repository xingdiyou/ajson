#include "ajson/ajson.h"
#include <iostream>

int main() {
  std::string str = R"(
  {
      "name": "John Doe",
      "age": 30,
      "email": "johndoe@example.com",
      "address": {
          "street": "123 Main St",
          "city": "Anytown",
          "state": "CA",
          "postalCode": "12345"
      },
      "phoneNumbers": [
          {
              "type": "home",
              "number": "555-555-5555"
          },
          {
              "type": "work",
              "number": "555-555-1234"
          }
      ],
      "isActive": true,
      "roles": ["admin", "editor"]
  }
  )";

  std::shared_ptr<ajson::JSON> json = ajson::JSON::Parse(str);
  std::cout << json->Dump();
  return 0;
}
