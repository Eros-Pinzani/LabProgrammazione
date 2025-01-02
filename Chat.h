#ifndef CHAT_H
#define CHAT_H

#include <utility>
#include <vector>
#include "Message.h"

class Chat {
public:
    Chat(std::shared_ptr<User> user1, std::shared_ptr<User> user2) : user1(std::move(user1)), user2(std::move(user2)) {}
    void addMessage(const Message &message);
    void displayChat() const;

private:
    std::shared_ptr<User> user1;
    std::shared_ptr<User> user2;
    std::vector<Message> messages;
};

#endif //CHAT_H
