#include <iostream>
#include <memory>
#include "../api/include/encryption.h"

int main() {
    std::string userMessage;
    do
    {
        std::cout << "Enter the message to encrypt or press N to end the program: \n";
    std::getline(std::cin, userMessage);
    
    if (std::toupper(userMessage[0]) == 'N') {
            std::cout << "Finished program" << std::endl;
            break;
        }

    // Create a shared pointer for the message directly
    auto message = std::make_shared<std::string>(std::move(userMessage));
    auto shift = std::make_shared<int>(3); // Set the shift value as needed


    crypto::Encryption encryptor(message, shift);

    encryptor.Encrypt();

    std::cout << "Encrypted message: " << *message << std::endl;
    } while (true);
    

    return 0;
}