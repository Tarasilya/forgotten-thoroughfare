#pragma once

#include <SFML/Network.hpp>

#include <string>

class Client{
    sf::TcpSocket socket;

public:
    Client();

    void Send(const std::string& action);
    
    std::vector<std::string> Receive();
};