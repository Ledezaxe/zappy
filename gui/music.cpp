//
// music.cpp for  in /home/ledezaxe/zappy
// 
// Made by Quentin Rouanet
// Login   <ledezaxe@epitech.net>
// 
// Started on  Thu Jul  3 18:17:01 2014 Quentin Rouanet
// Last update Thu Jul  3 18:32:16 2014 Quentin Rouanet
//

#include "music.hpp"

Music::Music(std::string path)
{
  this->load_state = music.openFromFile(path);
}

Music::~Music()
{

}

bool Music::play_music(bool loop)
{
  if (!this->load_state)
    return false;
  this->music.setLoop(loop);
  this->music.play();
  return true;
}

bool Music::stop_music()
{
  if (!this->load_state)
    return false;
  this->music.stop();
  return true;
}
