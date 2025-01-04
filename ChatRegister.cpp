#include "ChatRegister.h"

Chat & ChatRegister::CreateNewOrGetChat(const std::shared_ptr<User>& user1, const std::shared_ptr<User>& user2) {
    const auto key = user1->getName() < user2->getName() ?
        std::make_pair(user1->getName(), user2->getName()) : std::make_pair(user2->getName(), user1->getName());
    if (chatRegister.find(key) == chatRegister.end()) {
        chatRegister[key] = Chat(user1, user2);
    }
    return chatRegister[key];
}

void ChatRegister::displayChatRegister() const {
    std::cout << "All chats in the register: " << std::endl;
    for (const auto &chat : chatRegister) {
        std::cout << "Chat between " << chat.first.second<< " and " << chat.first.first << std::endl;
    }
}