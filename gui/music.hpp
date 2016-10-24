//
// music.hpp for  in /home/ledezaxe/zappy
// 
// Made by Quentin Rouanet
// Login   <ledezaxe@epitech.net>
// 
// Started on  Thu Jul  3 18:11:44 2014 Quentin Rouanet
// Last update Sun Jul 13 19:07:22 2014 Quentin Rouanet
//

#ifndef MUSIC_H__
# define MUSIC_H__

#include "includes.hpp"

class Music
{
public:
  Music(std::string path);
  ~Music();

private:
  sf::Music music;
  int load_state;

public:
  bool play_music(bool loop);
  bool stop_music();
};

#endif /* !MUSIC_H__ */
