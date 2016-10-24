//
// cellule.cpp for  in /home/ledezaxe/test_sfml
// 
// Made by Quentin Rouanet
// Login   <ledezaxe@epitech.net>
// 
// Started on  Sat Jun 28 14:57:52 2014 Quentin Rouanet
// Last update Wed Jul  2 17:20:32 2014 Quentin Rouanet
//

#include "cellule.hpp"

// Ctor/Dtor

Cellule::Cellule(int joueur, int linemate, int deraumere, int cibur, int mendiane, int phiras, int thystame, int oeufs, int nourriture)
{
  this->_joueurs = joueur;
  this->_linemate = linemate;
  this->_deraumere = deraumere;
  this->_cibur = cibur;
  this->_mendiane = mendiane;
  this->_phiras = phiras;
  this->_thystame = thystame;
  this->_oeufs = oeufs;
  this->_nourriture = nourriture;
}

Cellule::~Cellule()
{

}

// getters

int Cellule::getJoueurs()
{
  return (this->_joueurs);
}

int Cellule::getOeufs()
{
  return (this->_oeufs);
}

int Cellule::getNourriture()
{
  return (this->_nourriture);
}

int Cellule::getLinemate()
{
  return (this->_linemate);
}

int Cellule::getDeraumere()
{
  return (this->_deraumere);
}

int Cellule::getCibur()
{
  return (this->_cibur);
}

int Cellule::getMendiane()
{
  return (this->_mendiane);
}

int Cellule::getPhiras()
{
  return (this->_phiras);
}

int Cellule::getThystame()
{
  return (this->_thystame);
}

// setters

void Cellule::setJoueurs(int value)
{
  this->_joueurs = value;
}

void Cellule::setOeufs(int value)
{
  this->_oeufs = value;
}

void Cellule::setNourriture(int value)
{
  this->_nourriture = value;
}

void Cellule::setLinemate(int value)
{
  this->_linemate = value;
}

void Cellule::setDeraumere(int value)
{
  this->_deraumere = value;
}

void Cellule::setCibur(int value)
{
  this->_cibur = value;
}

void Cellule::setMendiane(int value)
{
  this->_mendiane = value;
}

void Cellule::setPhiras(int value)
{
  this->_phiras = value;
}

void Cellule::setThystame(int value)
{
  this->_thystame = value;
}
