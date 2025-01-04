#include "Chat.h"

void Chat::addMessage(const Message &message) {
    if ((user1==message.getSender() && user2==message.getReceiver()) || (user2==message.getSender() && user1==message.getReceiver())) {
        messages.push_back(message);
    }
    else
        throw std::runtime_error("This message doesn't belong to this chat.");
}

void Chat::displayChat() const {
    std::cout << "Chat between " << user1->getName() << " and " << user2->getName() << ": " << std::endl;
    for (const auto &message : messages) {
        message.display();
    }
    std::cout << "------------------------------" << std::endl;
}