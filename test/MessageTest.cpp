#include "gtest/gtest.h"
#include "../Message.h"

TEST(MessageTest, Getter) {
    auto sender = std::make_shared<User>("Eros");
    auto receiver = std::make_shared<User>("Irene");
    Message message (sender, receiver, "Hello, how are you?");

    ASSERT_EQ(message.getSender()->getName(), "Eros" );
    ASSERT_EQ(message.getReceiver()->getName(), "Irene" );
}

TEST(MessageTest, Display) {
    auto sender = std::make_shared<User>("Eros");
    auto receiver = std::make_shared<User>("Irene");
    Message message (sender, receiver, "Hello, how are you?");

    testing::internal::CaptureStdout();
    message.display();
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, "From Eros To Irene - Message: Hello, how are you?\n");
}