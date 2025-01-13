#include "User.h"

User::User(const std::string& name, const std::string& lastName, const std::string& phoneNumber, const std::string& profilePicturePath) :
    firstName(name), lastName(lastName), phoneNumber(phoneNumber), profilePicturePath(profilePicturePath) {
    if (name.empty() || lastName.empty() || phoneNumber.empty() || profilePicturePath.empty()) {
        throw std::invalid_argument("User data cannot be empty.");
    }
}

std::string User::getName() const {
    return firstName;
}

std::string User::getLastName() const {
    return lastName;
}

std::string User::getPhoneNumber() const {
    return phoneNumber;
}

std::string User::getProfilePicturePath() const {
    return profilePicturePath;
}