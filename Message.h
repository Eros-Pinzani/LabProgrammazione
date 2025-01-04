
#ifndef MESSAGE_H
#define MESSAGE_H

#include <memory>
#include <iostream>
#include <utility>
#include "User.h"

class Message {
public:
    Message(const std::shared_ptr<User>& sender, const std::shared_ptr<User>& receiver, std::string content) :
        sender(sender), receiver(receiver), content(std::move(content)) {}
    std::shared_ptr<User> getSender() const;
    std::shared_ptr<User> getReceiver() const;
    void display() const;

private:
    std::shared_ptr<User> sender;
    std::shared_ptr<User> receiver;
    std::string content;
};

#endif //MESSAGE_H