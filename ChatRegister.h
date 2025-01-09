#ifndef CHATREGISTER_H
#define CHATREGISTER_H

#include <map>
#include "Chat.h"

class ChatRegister {
public:
    Chat &CreateNewOrGetChat(const std::shared_ptr<User>& user1, const std::shared_ptr<User>& user2);
    size_t countChats() const;
    std::vector<std::string> searchMessages(const std::string& word) const;
    std::string displayChatRegister() const;

private:
    std::map<std::pair<std::string, std::string>, Chat> chatRegister;
};

#endif //CHATREGISTER_H