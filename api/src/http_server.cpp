
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include <httplib.h>
#include "../include/encryption.h"
#include "../include/http_server.h"

namespace crypto{
    Server::Server():encryption_(std::make_shared<Encryption>()),
                     server_(std::make_shared<httplib::Server>()),
                     text_(std::make_shared<std::string>()),
                     response_(std::make_shared<std::string>()){}
    Server::~Server(){
        std::cout << "Server was closed" << std::endl;
    }

    void Server::InitializationServer() {
    server_->Post("/", [&](const httplib::Request& req, httplib::Response& res) {
        // Check if the request has a body
        if (req.has_header("Content-Length") && req.body.length() > 0) {
            try {
                // Parse the JSON body
                auto json_body = nlohmann::json::parse(req.body);
                *text_ = json_body["text"];
                
                // Encrypt the message
                EncryptionMessage();
                
                // Generate response
                GenerateResponse(text_);
                res.set_content(*response_, "application/json");
            } catch(const std::exception& e) {
                res.set_content("Error parsing JSON body", "text/plain");
            }
        } else {
            res.set_content("No message provided in the request body", "text/plain");
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