#include "Message.h"

Message::Message(const std::shared_ptr<User> &sender, const std::shared_ptr<User> &receiver, std::string content) :
    sender(sender), receiver(receiver), content(std::move(content)), read(false) {
    if (!this->sender || !this->receiver) {
        throw std::invalid_argument("Sender and receiver cannot be null.");
    }
    if (this->content.empty()) {
        throw std::invalid_argument("Message content cannot be empty.");
    }
    if (this->sender == this->receiver) {
        throw std::invalid_argument("Sender and receiver cannot be the same user.");
    }
}

std::shared_ptr<User> Message::getSender() const {
    return sender;
}

std::shared_ptr<User> Message::getReceiver() const {
    return receiver;
}

std::string Message::getContent() const {
    return content;
}

bool Message::isRead() const {
    return read;
}

void Message::setRead() {
    read = true;
}

std::string Message::display() const{
    return "From " + sender->getName() + " To " + receiver->getName() + " - Message: " + content;
}