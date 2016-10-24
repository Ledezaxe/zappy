//
// main.cpp for  in /home/ledezaxe/zappy
// 
// Made by Quentin Rouanet
// Login   <ledezaxe@epitech.net>
// 
// Started on  Wed Jul  2 14:46:23 2014 Quentin Rouanet
// Last update Sun Jul 13 18:44:20 2014 Quentin Rouanet
//

#include "includes.hpp"

int main(int ac, char **av)
{
  if (ac != 5 || strcmp(av[1], "-p") != 0 || strcmp(av[3], "-h") != 0)
    {
      std::cout << "Usage :./GUI -p port -h adresse_IP" << std::endl;
      return 0;
    }

  std::string ip;

  ip = av[4];

  Network client(ip, atoi(av[2]));

  if (client.connect_server() == false)
    {
      std::cout << "erreur lors de la connexion au serveur" << std::endl;
      return 0;
    }

  client.communication();

// suite ...

}
