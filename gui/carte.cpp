//
// carte.cpp for  in /home/ledezaxe/test_sfml
// 
// Made by Quentin Rouanet
// Login   <ledezaxe@epitech.net>
// 
// Started on  Sat Jun 28 13:58:42 2014 Quentin Rouanet
// Last update Sun Jul 13 13:41:33 2014 Quentin Rouanet
//

#include "carte.hpp"

Carte::Carte(int longeur, int largeur)
{
  this->_longeur = longeur;
  this->_largeur = largeur;
}

Carte::~Carte()
{

}

int Carte::getLongeur()
{
  return (this->_longeur);
}

int Carte::getLargeur()
{
  return (this->_largeur);
}

void Carte::setLongeur(int value)
{
  this->_longeur = value;
}

void Carte::setLargeur(int value)
{
  this->_largeur = value;
}

void Carte::setCellule(int x, int y, Cellule &cell)
{
  this->plan[x][y] = cell;
}

Cellule Carte::getCellule(int x, int y)
{
  return (this->plan[x][y]);
}
