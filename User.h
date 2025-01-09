#ifndef USER_H
#define USER_H

#include <string>
#include <utility>

class User {
public:
    User(std::string name, std::string lastName, std::string phoneNumber, std::string profilePicturePath) :
        firstName(std::move(name)), lastName(std::move(lastName)), phoneNumber(std::move(phoneNumber)), profilePicturePath(std::move(profilePicturePath)) {}
    std::string getName() const;
    std::string getLastName() const;
    std::string getPhoneNumber() const;
    std::string getProfilePicturePath() const;

private:
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string profilePicturePath;
};

#endif //USER_H