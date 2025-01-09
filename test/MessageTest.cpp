#include "gtest/gtest.h"
#include "../Message.h"

TEST(MessageTest, Getters) {
    const auto sender = std::make_shared<User>("Eros", "Pinzani", "1234567890", "path/to/picture");
    const auto receiver = std::make_shared<User>("Silvia", "Taddei", "0987654321", "path/to/picture1");
    Message message (sender, receiver, "Hello!");

    ASSERT_EQ(message.getSender()->getName(), "Eros" );
    ASSERT_EQ(message.getReceiver()->getName(), "Silvia" );
    ASSERT_EQ(message.getContent(), "Hello!" );
    ASSERT_EQ(message.isRead(), false );

    message.setRead();
    ASSERT_EQ(message.isRead(), true );
}

TEST(MessageTest, EmptyContent) {
    const auto sender = std::make_shared<User>("Eros", "Pinzani", "1234567890", "path/to/picture");
    const auto receiver = std::make_shared<User>("Silvia", "Taddei", "0987654321", "path/to/picture1");

    EXPECT_THROW(Message message (sender, receiver, "");, std::invalid_argument);
}

TEST(MessageTest, SameSenderReceiver) {
    const auto user = std::make_shared<User>("Eros", "Pinzani", "1234567890", "path/to/picture");

    EXPECT_THROW(Message message (user, user, "Hello!");, std::invalid_argument);
}

TEST(MessageTest, Display) {
    const auto sender = std::make_shared<User>("Eros", "Pinzani", "1234567890", "path/to/picture");
    const auto receiver = std::make_shared<User>("Silvia", "Taddei", "0987654321", "path/to/picture1");
    const Message message (sender, receiver, "Hello, how are you?");

    ASSERT_EQ(message.display(), "From Eros To Silvia - Message: Hello, how are you?");
}