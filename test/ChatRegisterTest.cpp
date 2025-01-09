#include "gtest/gtest.h"
#include "../ChatRegister.h"

TEST(ChatRegisterTest, CreateNewOrGetChat) {
    const auto user1 = std::make_shared<User>("Eros", "Pinzani", "1234567890", "path/to/picture");
    const auto user2 = std::make_shared<User>("Silvia", "Taddei", "0987654321", "path/to/picture1");
    const auto user3 = std::make_shared<User>("Maurizio", "Pinzani", "1357924680", "path/to/picture2");

    ChatRegister chatRegister;
    Chat &chat1 = chatRegister.CreateNewOrGetChat(user1, user2);
    Chat &chat2 = chatRegister.CreateNewOrGetChat(user1, user3);
    Chat &chat3 = chatRegister.CreateNewOrGetChat(user1, user2);

    ASSERT_NE(&chat1, &chat2);
    ASSERT_EQ(&chat1, &chat3);
    ASSERT_EQ(chatRegister.countChats(), 2);
}

TEST(ChatRegisterTest, SearchMessages) {
    const auto user1 = std::make_shared<User>("Eros", "Pinzani", "1234567890", "path/to/picture");
    const auto user2 = std::make_shared<User>("Silvia", "Taddei", "0987654321", "path/to/picture1");
    const auto user3 = std::make_shared<User>("Maurizio", "Pinzani", "1357924680", "path/to/picture2");

    ChatRegister chatRegister;
    Chat &chat1 = chatRegister.CreateNewOrGetChat(user1, user2);
    Chat &chat2 = chatRegister.CreateNewOrGetChat(user1, user3);
    chat1.addMessage(Message(user1, user2, "Hi Silvia!"));
    chat1.addMessage(Message(user2, user1, "Hello Eros!"));
    chat2.addMessage(Message(user1, user3, "Hi Maurizio!"));
    chat2.addMessage(Message(user3, user1, "Hi Eros!"));

    std::vector<std::string> results = chatRegister.searchMessages("Silvia");
    ASSERT_EQ(results.size(), 1);
    ASSERT_EQ(results[0], "From Eros To Silvia - Message: Hi Silvia!");

    results = chatRegister.searchMessages("Dario");
    ASSERT_EQ(results.size(), 1);
    ASSERT_EQ(results[0], "No messages found containing the word 'Dario'.");
}

TEST(ChatRegisterTest, DisplayChatRegister) {
    const auto user1 = std::make_shared<User>("Eros", "Pinzani", "1234567890", "path/to/picture");
    const auto user2 = std::make_shared<User>("Silvia", "Taddei", "0987654321", "path/to/picture1");
    const auto user3 = std::make_shared<User>("Maurizio", "Pinzani", "1357924680", "path/to/picture2");

    ChatRegister chatRegister;
    chatRegister.CreateNewOrGetChat(user1, user2);
    chatRegister.CreateNewOrGetChat(user1, user3);

    std::string output = "All chats in the register:\n";
    output += "Chat between Maurizio and Eros\n";
    output += "Chat between Silvia and Eros\n";

    ASSERT_EQ(chatRegister.displayChatRegister(), output);
}