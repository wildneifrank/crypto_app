#include "../include/encryption.h"
#include <iostream>
#include <fstream>
#include <cctype>

namespace crypto {
    Encryption::Encryption():
                            message_(std::make_shared<std::string>()),
                            shift_(std::make_shared<int>(3)){};
    Encryption::~Encryption(){};

    void Encryption::Encrypt(std::shared_ptr<std::string> message_received_){
        encrypted_message_ = *message_received_;

        for (char& character : encrypted_message_) {
            if (isalpha(character)) {
                char base = isupper(character) ? 'A' : 'a';
                character = static_cast<char>((character - base + *shift_) % 26 + base);
            }
        }
        *message_ = encrypted_message_;
    }

} // namespace crypto
