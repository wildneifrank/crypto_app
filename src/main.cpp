#include <iostream>
#include "../api/include/http_server.h"

int main() {
    crypto::Server server;
    server.InitializationServer();
    std::cout << "Server started successfully. Listening on port 8080" << std::endl;

    return 0;
}




