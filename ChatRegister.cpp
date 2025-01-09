#include "ChatRegister.h"

Chat & ChatRegister::CreateNewOrGetChat(const std::shared_ptr<User>& user1, const std::shared_ptr<User>& user2) {
    const auto key = user1->getName() < user2->getName() ?
        std::make_pair(user1->getName(), user2->getName()) : std::make_pair(user2->getName(), user1->getName());
    if (chatRegister.find(key) == chatRegister.end()) {
        chatRegister[key] = Chat(user1, user2);
    }
    return chatRegister[key];
}

size_t ChatRegister::countChats() const {
    return chatRegister.size();
}

std::vector<std::string> ChatRegister::searchMessages(const std::string &word) const {
    std::vector<std::string> results;
    for (const auto &chat : chatRegister) {
        const auto chatMessages = chat.second.searchMessage(word);
        results.insert(results.end(), chatMessages.begin(), chatMessages.end());
    }
    if (results.empty()) {
        results.push_back("No messages found containing the word '" + word + "'.");
    }
    return results;
}

std::string ChatRegister::displayChatRegister() const {
    std::string registryOutput = "All chats in the register:\n";
    for (const auto &chat : chatRegister) {
        registryOutput += "Chat between " + chat.first.second + " and " + chat.first.first + "\n";
    }
    return registryOutput;
}