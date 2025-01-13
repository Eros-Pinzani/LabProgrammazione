#ifndef USER_H
#define USER_H

#include <string>
#include <utility>
#include <stdexcept>

class User {
public:
    User(const std::string& name, const std::string& lastName, const std::string& phoneNumber, const std::string& profilePicturePath);
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