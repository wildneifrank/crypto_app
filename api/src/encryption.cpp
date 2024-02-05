#include "../include/encryption.h"
#include <iostream>
#include <fstream>
#include <cctype>

namespace crypto {
    Encryption::Encryption(std::shared_ptr<std::string> message, 
                            std::shared_ptr<int> shift):
                            message_(message),
                            shift_(shift){};
    Encryption::~Encryption(){};

    void Encryption::Encrypt(){
        encrypted_message_ = *message_;

        for (char& character : encrypted_message_) {
            if (isalpha(character)) {
                char base = isupper(character) ? 'A' : 'a';
                character = static_cast<char>((character - base + *shift_) % 26 + base);
            }
        }
        *message_ = encrypted_message_;
    }

} // namespace crypto
