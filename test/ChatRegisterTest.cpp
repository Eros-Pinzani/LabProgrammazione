#include "gtest/gtest.h"
#include "../ChatRegister.h"

TEST(ChatRegisterTest, CreateNewOrGetChat) {
    const auto user1 = std::make_shared<User>("Eros");
    const auto user2 = std::make_shared<User>("Silvia");
    const auto user3 = std::make_shared<User>("Maurizio");

    ChatRegister chatRegister;
    Chat &chat1 = chatRegister.CreateNewOrGetChat(user1, user2);
    Chat &chat2 = chatRegister.CreateNewOrGetChat(user1, user3);
    Chat &chat3 = chatRegister.CreateNewOrGetChat(user1, user2);

    ASSERT_NE(&chat1, &chat2);
    ASSERT_EQ(&chat1, &chat3);
}

TEST(ChatRegisterTest, DisplayChatRegister) {
    const auto user1 = std::make_shared<User>("Eros");
    const auto user2 = std::make_shared<User>("Silvia");

    ChatRegister chatRegister;
    chatRegister.CreateNewOrGetChat(user1, user2);

    testing::internal::CaptureStdout();
    chatRegister.displayChatRegister();
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, "All chats in the register: \nChat between Silvia and Eros\n");
}