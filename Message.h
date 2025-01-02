
#ifndef MESSAGE_H
#define MESSAGE_H

#include <memory>
#include <iostream>
#include "User.h"

class Message {
public:
    Message(std::shared_ptr<User> sender, std::shared_ptr<User> receiver, const std::string &content) :
        sender(std::move(sender)), receiver(std::move(receiver)), content(content) {}
    std::shared_ptr<User> getSender() const;
    std::shared_ptr<User> getReceiver() const;
    void display() const;

private:
    std::shared_ptr<User> sender;
    std::shared_ptr<User> receiver;
    std::string content;
};

#endif //MESSAGE_H
