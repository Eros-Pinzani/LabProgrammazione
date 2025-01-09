#include "gtest/gtest.h"
#include "../Chat.h"

TEST(ChatTest, AddandCountMessages) {
    const auto user1 = std::make_shared<User>("Eros", "Pinzani", "1234567890", "path/to/picture");
    const auto user2 = std::make_shared<User>("Silvia", "Taddei", "0987654321", "path/to/picture1");
    Chat chat(user1, user2);
    const Message message1(user1, user2, "Hello, how are you?");
    const Message message2(user2, user1, "Hi, I'm fine, thank you!");
    chat.addMessage(message1);
    chat.addMessage(message2);

    ASSERT_EQ(chat.countMessages(), 2);
    ASSERT_EQ(chat.countUnreadMessages(), 2);

    chat.readMessage(0);
    ASSERT_EQ(chat.countUnreadMessages(), 1);
}

TEST(ChatTest, SearchMessage) {
    auto user1 = std::make_shared<User>("Silvia", "Taddei", "1234567890", "path/to/picture1");
    auto user2 = std::make_shared<User>("Maurizio", "Pinzani", "0987654321", "path/to/picture2");

    Chat chat(user1, user2);
    Message message1(user1, user2, "Hi Maurizio!");
    Message message2(user2, user1, "Hello Silvia!");
    Message message3(user1, user2, "How are you, Maurizio?");
    Message message4(user2, user1, "I'm fine, Silvia. Thank you!");
    chat.addMessage(message1);
    chat.addMessage(message2);
    chat.addMessage(message3);
    chat.addMessage(message4);

    auto results = chat.searchMessage("Maurizio");
    ASSERT_EQ(results.size(), 2);
    ASSERT_EQ(results[0], "From Silvia To Maurizio - Message: Hi Maurizio!");
    ASSERT_EQ(results[1], "From Silvia To Maurizio - Message: How are you, Maurizio?");

    results = chat.searchMessage("Rosanna");
    ASSERT_EQ(results.empty(), true);
}

TEST(ChatTest, Display) {
    const auto user1 = std::make_shared<User>("Eros", "Pinzani", "1234567890", "path/to/picture");
    const auto user2 = std::make_shared<User>("Silvia", "Taddei", "0987654321", "path/to/picture1");
    Chat chat(user1, user2);
    const Message message1(user1, user2, "Hello, how are you?");
    const Message message2(user2, user1, "Hi, I'm fine, thank you!");
    chat.addMessage(message1);
    chat.addMessage(message2);

    std::string expected = "Chat between Eros and Silvia:\n";
    expected += "From Eros To Silvia - Message: Hello, how are you?\n";
    expected += "From Silvia To Eros - Message: Hi, I'm fine, thank you!\n";
    expected += "------------------------------\n";

    ASSERT_EQ(chat.displayChat(), expected);
}

TEST(ChatTest, AddMessageException) {
    const auto user1 = std::make_shared<User>("Eros", "Pinzani", "1234567890", "path/to/picture");
    const auto user2 = std::make_shared<User>("Silvia", "Taddei", "0987654321", "path/to/picture1");
    const auto user3 = std::make_shared<User>("Maurizio", "Pinzani", "1357924680", "path/to/picture2");
    Chat chat(user1, user2);
    const Message message(user1, user3, "Hello, how are you?");

    EXPECT_THROW(chat.addMessage(message), std::runtime_error);
}

TEST(ChatTest, ReadMessageException) {
    const auto user1 = std::make_shared<User>("Eros", "Pinzani", "1234567890", "path/to/picture");
    const auto user2 = std::make_shared<User>("Silvia", "Taddei", "0987654321", "path/to/picture1");
    Chat chat(user1, user2);
    const Message message(user1, user2, "Hello, how are you?");
    chat.addMessage(message);
    EXPECT_THROW(chat.readMessage(1), std::out_of_range);
}