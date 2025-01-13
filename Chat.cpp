#include "Chat.h"

void Chat::addMessage(const Message &message) {
    if ((user1==message.getSender() && user2==message.getReceiver()) || (user2==message.getSender() && user1==message.getReceiver())) {
        messages.push_back(message);
    }
    else
        throw std::runtime_error("This message doesn't belong to this chat.");
}

std::string Chat::readMessage(int i) {
    if (i >= messages.size()) {
        throw std::out_of_range("Message index out of range.");
    }
    Message& message = messages[i];
    message.setRead();
    return message.display();
}

size_t Chat::countMessages() const {
    return messages.size();
}

size_t Chat::countUnreadMessages() const {
    size_t counter = 0;
    for (const auto &message : messages) {
        if (!message.isRead()) {
            ++counter;
        }
    }
    return counter;
}

std::vector<std::string> Chat::searchMessage(const std::string &word) const {
    std::vector<std::string> foundMessages;
    for (const auto &message : messages) {
        if (message.getContent().find(word) != std::string::npos) {
            foundMessages.push_back(message.display());
        }
    }
    return foundMessages;
}

std::string Chat::displayChat() const {
    std::string chat = "Chat between " + user1->getName() + " and " + user2->getName() + ":\n";
    for (const auto &message : messages) {
        chat += message.display() + "\n";
    }
    chat += "------------------------------\n";
    return chat;
}