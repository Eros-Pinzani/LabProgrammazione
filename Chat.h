#ifndef CHAT_H
#define CHAT_H

#include <vector>
#include "Message.h"

class Chat {
public:
    Chat() = default; // default constructor needed for the map operator [] in ChatRegister class to work properly
    Chat(const std::shared_ptr<User>& user1, const std::shared_ptr<User>& user2) : user1(user1), user2(user2) {}
    void addMessage(const Message &message);
    void displayChat() const;

private:
    std::shared_ptr<User> user1;
    std::shared_ptr<User> user2;
    std::vector<Message> messages;
};

#endif //CHAT_H