#ifndef MESSAGE_H
#define MESSAGE_H

#include <memory>
#include <iostream>
#include <utility>
#include "User.h"

class Message {
public:
    Message(const std::shared_ptr<User>& sender, const std::shared_ptr<User>& receiver, std::string content);
    std::shared_ptr<User> getSender() const;
    std::shared_ptr<User> getReceiver() const;
    std::string getContent() const;
    bool isRead() const;
    void setRead();
    std::string display() const;

private:
    std::shared_ptr<User> sender;
    std::shared_ptr<User> receiver;
    std::string content;
    bool read;
};

#endif //MESSAGE_H