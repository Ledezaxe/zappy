//
// network.cpp for  in /home/ledezaxe/test_sfml
// 
// Made by Quentin Rouanet
// Login   <ledezaxe@epitech.net>
// 
// Started on  Mon Jun 30 15:14:27 2014 Quentin Rouanet
// Last update Sun Jul 13 19:03:40 2014 Quentin Rouanet
//

#include "network.hpp"

// Ctor & Dtor

Network::Network(std::string ip, int port)
{
  this->status = this->socket.connect(ip, port);
}

Network::~Network()
{
  std::cout << "CLIENT FERMÉ" << std::endl;
}

// Functions

bool Network::connect_server()
{
  if (status != sf::Socket::Done)
    {
      std::cout << "erreur lors de la connexion avec le serveur" << std::endl;
      return false;
    }

  this->selector.add(this->socket);
  return true;
}

bool Network::communication()
{
  while (this->quit)
    {
      if (this->selector.wait(sf::seconds(3)))
	{
	  this->quit = this->reception();
	}
    }
  return true;
}

int Network::envoi(std::string send)
{
  if (this->socket.send(send.c_str(), send.length()) != sf::Socket::Done)
    {
      std::cout << "erreur avec l'envoi" << std::endl;
      return 0;
    }
  return 1;
}

int Network::reception()
{
  char receive[1024];
  std::size_t size;

  if (this->socket.receive(receive, 1024, size) != sf::Socket::Done)
    {
      std::cout << "erreur avec la reception" << std::endl;
      return 0;
    }

  this->data = receive;
  return 1;
}

// getters / setters

std::string Network::getData()
{
  return this->data;
}

void Network::setData(std::string &value)
{
  this->data = value;
}
