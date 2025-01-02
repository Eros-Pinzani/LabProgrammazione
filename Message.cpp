#include "Message.h"

std::shared_ptr<User> Message::getSender() const {
    return sender;
}

std::shared_ptr<User> Message::getReceiver() const {
    return receiver;
}

void Message::display() const{
    std::cout << "From: " << sender->getName() << " To: " << receiver->getName() << " Message: " << content << std::endl;
}
