#include "Chat.h"
#include "ChatRegister.h"
#include "Message.h"
#include "User.h"

int main() {
    try {
        const auto user1 = std::make_shared<User>("Silvia", "Taddei", "1234567890", "path/to/picture1");
        const auto user2 = std::make_shared<User>("Maurizio", "Pinzani", "0987654321", "path/to/picture2");
        const auto user3 = std::make_shared<User>("Rosanna", "Cavicchi", "1357924680", "path/to/picture3");
        //const auto user4 = std::make_shared<User>("", "", "", ""); // This line will throw an exception

        ChatRegister chatRegister;
        Chat &chat = chatRegister.CreateNewOrGetChat(user1, user2);
        Chat &chat2 = chatRegister.CreateNewOrGetChat(user1, user3);


        const Message message1 (user1, user2, "Hi Maurizio!");
        const Message message2 (user2, user1, "Hello Silvia!");

        const Message message3 (user1, user3, "Good morning Rosanna!");
        const Message message4 (user3, user1, "Hi Silvia! How are you?");

        //const Message message5 (user1, user2, ""); // This line will throw an exception
        //const Message message6 (user1, user1, "Hi Silvia!"); // This line will throw an exception

        chat.addMessage(message1);
        chat.addMessage(message2);
        std::cout << "Total messages in chat: " << chat.countMessages() << std::endl;
        std::cout << "Unread messages in chat: " << chat.countUnreadMessages() << std::endl;
        std::cout << "First message: " << chat.readMessage(0)<< std::endl;
        std::cout << "Unread messages in chat after the first reading: " << chat.countUnreadMessages() << std::endl;
        std::cout << "Second message: " << chat.readMessage(1)<< std::endl;
        std::cout << "Unread messages in chat after the second reading: " << chat.countUnreadMessages() << std::endl;
        //std::cout << "Third message: " << chat.readMessage(2)<< std::endl; // This line will throw an exception
        std::cout << chat.displayChat() << std::endl;

        chat2.addMessage(message3);
        chat2.addMessage(message4);
        std::cout << chat2.displayChat() << std::endl;

        //chat2.addMessage(message1); // This line will throw an exception

        std::cout << "Searching for messages containing 'Silvia': " << std::endl;
        for (const auto &message : chatRegister.searchMessages("Silvia")) {
            std::cout << message << std::endl;
        }
        std::cout << "------------------------------" << std::endl;
        std::cout << "Searching for messages containing 'Dario': " << std::endl;
        for (const auto &message : chatRegister.searchMessages("Dario")) {
            std::cout << message << std::endl;
        }
        std::cout << "------------------------------" << std::endl;

        std::cout << chatRegister.displayChatRegister() << std::endl;
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::out_of_range &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}