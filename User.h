#ifndef USER_H
#define USER_H

#include <string>
#include <utility>

class User {
public:
    explicit User(std::string  name) : name(std::move(name)) {}
    std::string getName() const;

private:
    std::string name;

};

#endif //USER_H