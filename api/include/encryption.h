#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <iostream>
#include <string>

namespace crypto {
    class Encryption{
        public:
        Encryption();
        ~Encryption();

        void Encrypt(const std::shared_ptr<std::string> message);

        private:
        std::shared_ptr<std::string> message_;
        std::string encrypted_message_;
        std::shared_ptr<int> shift_;
    };
} // namespace crypto

#endif // ENCRYPTION_H