#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "util/config_reader.h"
#include "client.h"

using namespace std;


Client::Client(){
    ConfigReader* network_config = new ConfigReader("network.txt");

    std::string server_name = network_config->GetString("SERVER_NAME");
    int server_port = network_config->GetInt("SERVER_PORT");

    socket.setBlocking(false);
    sf::Socket::Status status = socket.connect(server_name.c_str(), server_port);
}

std::vector<std::string> Client::Receive() {
    std::vector<std::string> actions;
    sf::Packet packet;
    while (socket.receive(packet) == sf::TcpSocket::Status::Done){
        std::cout << "received" << "\n";
        std::string action;
        packet >> action;
        actions.push_back(action);
    }
    return actions;
}

void Client::Send(const std::string& action){
    sf::Packet packet;
    packet << action;
    socket.send(packet);
}
