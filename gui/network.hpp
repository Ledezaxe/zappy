//
// network.hpp for  in /home/ledezaxe/test_sfml
// 
// Made by Quentin Rouanet
// Login   <ledezaxe@epitech.net>
// 
// Started on  Mon Jun 30 14:42:09 2014 Quentin Rouanet
// Last update Sun Jul 13 19:03:26 2014 Quentin Rouanet
//

#ifndef NETWORK_H__
# define NETWORK_H__

#include "include.hpp"

class Network
{
public:
  Network(std::string ip, int port);
  ~Network();

private:

  sf::SocketSelector selector;
  sf::TcpSocket socket;
  sf::Socket::Status status;
  std::string data;
  int quit;

public:

  bool connect_server();
  bool communication();
  int reception();
  int envoi(std::string data);

//getters / setters

  std::string getData();
  void setData(std::string &send);

};

#endif /* !NETWORK_H__ */
