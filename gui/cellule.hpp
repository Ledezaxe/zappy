//
// cellule.hpp for  in /home/ledezaxe/test_sfml
// 
// Made by Quentin Rouanet
// Login   <ledezaxe@epitech.net>
// 
// Started on  Sat Jun 28 14:28:26 2014 Quentin Rouanet
// Last update Sun Jul 13 09:57:37 2014 same philipe
//

#ifndef CELLULE_H__
# define CELLULE_H__

#include "includes.hpp"

class Cellule
{
public:
  Cellule(int joueur, int linemate, int deraumere, int cibur, int mendiane,\
	  int phiras, int thystame, int oeufs, int nourriture);
  ~Cellule();

private:

  int _joueurs;
  int _oeufs;
  int _nourriture;

// pierres

  int _linemate;
  int _deraumere;
  int _cibur;
  int _mendiane;
  int _phiras;
  int _thystame;

public:

// getters

  int getJoueurs();
  int getOeufs();
  int getNourriture();
  int getLinemate();
  int getDeraumere();
  int getCibur();
  int getMendiane();
  int getPhiras();
  int getThystame();

// setters

  void setJoueurs(int value);
  void setOeufs(int value);
  void setNourriture(int value);
  void setLinemate(int value);
  void setDeraumere(int value);
  void setCibur(int value);
  void setMendiane(int value);
  void setPhiras(int value);
  void setThystame(int value);

};


// couleurs des pierres
// linemate = vert foncé  deraumere = rouge  cibur = violet  mendiane = orange  phiras = bleu  thystame = gris

#endif /* !CELLULE_H__ */
