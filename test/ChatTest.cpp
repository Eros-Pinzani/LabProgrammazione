#include "gtest/gtest.h"
#include "../Chat.h"

TEST(ChatTest, AddMessageAndDisplay) {
    auto user1 = std::make_shared<User>("Eros");
    auto user2 = std::make_shared<User>("Irene");
    Chat chat(user1, user2);
    Message message1(user1, user2, "Hello, how are you?");
    Message message2(user2, user1, "Hi, I'm fine, thank you!");
    chat.addMessage(message1);
    chat.addMessage(message2);

    testing::internal::CaptureStdout();
    chat.displayChat();
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, "Chat between Eros and Irene: \nFrom Eros To Irene - Message: Hello, how are you?\nFrom Irene To Eros - Message: Hi, I'm fine, thank you!\n------------------------------\n");
}

TEST(ChatTest, AddMessageException) {
    auto user1 = std::make_shared<User>("Eros");
    auto user2 = std::make_shared<User>("Irene");
    auto user3 = std::make_shared<User>("Alessandro");
    Chat chat(user1, user2);
    Message message(user1, user3, "Hello, how are you?");

    EXPECT_THROW(chat.addMessage(message), std::runtime_error);
}