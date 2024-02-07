#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include <iostream>
#include <string>
#include "httplib.h"
#include "encryption.h"
#include "../include/http_server.h"

namespace crypto {
    class Server{
        public:
        Server();
        ~Server();
        void InitializationServer();
        void EncryptionMessage();
        void GenerateResponse(const std::shared_ptr<std::string> encryptedMessage);
        
        private:
        std::shared_ptr<httplib::Server> server_;
        std::shared_ptr<Encryption> encryption_;
        std::shared_ptr<std::string> text_;
        std::shared_ptr<std::string> response_;
    };
} // namespace crypto

#endif // HTTP_SERVER_H