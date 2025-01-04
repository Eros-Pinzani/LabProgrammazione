#include "Chat.h"
#include "ChatRegister.h"
#include "Message.h"
#include "User.h"

int main() {
    const auto user1 = std::make_shared<User>("Silvia");
    const auto user2 = std::make_shared<User>("Maurizio");
    const auto user3 = std::make_shared<User>("Rosanna");

    ChatRegister chatRegister;
    Chat &chat = chatRegister.CreateNewOrGetChat(user1, user2);
    Chat &chat2 = chatRegister.CreateNewOrGetChat(user1, user3);

    const Message message1 (user1, user2, "Hi Maurizio!");
    const Message message2 (user2, user1, "Hello Silvia!");

    const Message message3 (user1, user3, "Hi Rosanna!");
    const Message message4 (user3, user1, "Hello Silvia!");

    try {
        chat.addMessage(message1);
        chat.addMessage(message2);
        chat.displayChat();

        chat2.addMessage(message3);
        chat2.addMessage(message4);
        chat2.displayChat();
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }

    chatRegister.displayChatRegister();

    return 0;
}