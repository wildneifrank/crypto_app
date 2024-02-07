#include "../include/http_server.h"
#include <iostream>
#include <string>
#include "../include/encryption.h"

namespace crypto{
    Server::Server():encryption_(std::make_shared<Encryption>()),
                     server_(std::make_shared<httplib::Server>()),
                     text_(std::make_shared<std::string>()),
                     response_(std::make_shared<std::string>()){}
    Server::~Server(){
        std::cout << "Server was closed" << std::endl;
    }

     void Server::InitializationServer(){
        server_->Post(R"(/(\w+))", [&](const httplib::Request& req, httplib::Response& res) {
            *text_ = req.matches[1];
            std::cout << "Received Text: " << *text_ << std::endl;
            try
            {
                EncryptionMessage();
                GenerateResponse(text_);
                
                res.set_content(*response_, "application/json");
            }
            catch(const std::exception& e)
            {
                res.set_content("Encryption failed", "text/plain");
            }
            
        });
        server_->listen("localhost", 8080);
    }
    void Server::EncryptionMessage(){
        encryption_->Encrypt(text_);
        std::cout << *text_ << std::endl;
    }
    void Server::GenerateResponse(const std::shared_ptr<std::string> encryptedMessage){
        *response_ = "{ \"encryptedMessage\": \"" + *encryptedMessage + "\" }";
    }
}