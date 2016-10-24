//
// parser.cpp for  in /home/ledezaxe/zappy
// 
// Made by Quentin Rouanet
// Login   <ledezaxe@epitech.net>
// 
// Started on  Sun Jul  6 17:30:52 2014 Quentin Rouanet
// Last update Sun Jul 13 09:58:58 2014 same philipe
//



bool command_selector(std::string cmd)
{
  std::string str;
  if (cmd.compare(1, 3, "msz") == 0)
    {
      str = substr(4);
      std::cout << str << std::endl;
    }
  //  else if (cmd.compare(1, 3, "bct") == 0)
    
  else
    return false;
  return true;
}

int		main(int ac, char **av)
{
  
  return (0);
}
