#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <iostream>
#include <string>

namespace crypto {
    class Encryption{
        public:
        Encryption(const std::shared_ptr<std::string> message, const std::shared_ptr<int> shift);
        ~Encryption();

        void Encrypt();

        private:
        std::shared_ptr<std::string> message_;
        std::string encrypted_message_;
        std::shared_ptr<int> shift_;
    };
} // namespace crypto

#endif // ENCRYPTION_H