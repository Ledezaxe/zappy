//
// carte.hpp for  in /home/ledezaxe/test_sfml
// 
// Made by Quentin Rouanet
// Login   <ledezaxe@epitech.net>
// 
// Started on  Wed Jun 25 12:53:40 2014 Quentin Rouanet
// Last update Sun Jul 13 09:56:59 2014 same philipe
//

#ifndef CARTE_H__
# define CARTE_H__

#include "includes.hpp"

class Carte
{
public:
  Carte(int longeur, int largeur);
  ~Carte();

private:
  int _longeur;
  int _largeur;

  std::vector< vector<Cellule> > plan;

public:

  int getLongeur();
  int getLargeur();
  void setLongeur(int value);
  void setLargeur(int value);

  void setCellule(int x, int y, Cellule &cell);
  Cellule getCellule(int x, int y);

};

#endif /* !CARTE_H__ */
