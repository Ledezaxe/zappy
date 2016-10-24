//
// windows.cpp for  in /home/samep/rendu/client_graphique
// 
// Made by same philipe
// Login   <samep@epitech.net>
// 
// Started on  Sat Jun 28 05:36:32 2014 same philipe
// Last update Sun Jul 13 19:09:19 2014 Quentin Rouanet
//


#include	"includes.hpp"

sf::RenderWindow	window;
sf::Texture		chars;
sf::Texture		oeuf;
sf::Texture		sol;
sf::Texture		sol2;
sf::Texture		sol3;
sf::Texture		sol4;
sf::Sprite		sprite_oeuf;
sf::Sprite		sprite_chars;
sf::Sprite		sprite_sol;
sf::Sprite		sprite_sol2;
sf::Sprite		sprite_sol3;
sf::Sprite		sprite_sol4;
enum Dir{Down, Left, Right, Up};
sf::Vector2i		anim(1, Down);
int			speed = 2;
bool			updateFPS = false;
sf::View		view;

void		clavier()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
      anim.y = Up;
      sprite_chars.move(0, -speed);
    }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
      anim.y = Down;
      sprite_chars.move(0, speed);
    }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
      anim.y = Left;
      sprite_chars.move(-speed, 0);
    }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
      anim.y = Right;
      sprite_chars.move(speed, 0);
    }
  if(sprite_chars.getPosition().x <= 0)
    sprite_chars.setPosition(sf::Vector2f(0, sprite_chars.getPosition().y));
  if(sprite_chars.getPosition().y <= 0)
    sprite_chars.setPosition(sf::Vector2f(sprite_chars.getPosition().x, 0));
}

int		main()
{
  window.create(sf::VideoMode(800, 600), "Zappy Bibicy");
  window.setFramerateLimit(60);

  sf::Clock time;
  if (!chars.loadFromFile("./tiles/perso.png"))
    {
      std::cout << "Erreur chargement perso.png" << std::endl;
    }
  if (!oeuf.loadFromFile("./tiles/oeuf.png"))
    {
      std::cout << "Erreur chargement oeuf.png" << std::endl;
    }
  if (!sol.loadFromFile("./tiles/sol.png"))
    {
      std::cout << "Erreur chargement ./tiles/sol.png" << std::endl;
    }
  if (!sol2.loadFromFile("./tiles/sol.png"))
    {
      std::cout << "Erreur chargement ./tiles/sol.png" << std::endl;
    }
 if (!sol3.loadFromFile("./tiles/sol.png"))
    {
      std::cout << "Erreur chargement ./tiles/sol.png" << std::endl;
    }
 if (!sol4.loadFromFile("./tiles/sol.png"))
    {
      std::cout << "Erreur chargement ./tiles/sol.png" << std::endl;
    }
  chars.setSmooth(true);
  sprite_chars.setTexture(chars);
  oeuf.setSmooth(true);
  sprite_oeuf.setTexture(oeuf);
  sol.setSmooth(true);
  sprite_sol.setTexture(sol);
  sol2.setSmooth(true);
  sprite_sol2.setTexture(sol);
  sol3.setSmooth(true);
  sprite_sol3.setTexture(sol);
  sol4.setSmooth(true);
  sprite_sol4.setTexture(sol);
  while(window.isOpen())
    {
      sf::Event event;

      while (window.pollEvent( event))
	{
	  if (event.type == sf::Event::Closed)
	    window.close();
	  if (event.type == sf::Event::KeyPressed)
	    updateFPS = true;
	  else
	    updateFPS = false;
	}
      clavier();
      if (updateFPS == true)
	{
	  if (time.getElapsedTime().asMilliseconds() >= 50)
	    {
	      anim.x--;
	      if (anim.x * 32 >= chars.getSize().x)
		anim.x = 2;
	      time.restart();
	    }
	}
      sprite_chars.setTextureRect(sf::IntRect(anim.x * 32, anim.y * 32, 32, 32));
      view.reset(sf::FloatRect(0, 0, 800, 600));
      sf::Vector2f position(400, 300);
      position.x = sprite_chars.getPosition().x + 16 - 400;
      position.y = sprite_chars.getPosition().y + 16 - 300;
      if (position.x < 0)
	position.x = 0;
      if (position.y < 0)
	position.y = 0;
      view.reset(sf::FloatRect(position.x, position.y, 800, 600));
      window.setView(view);
      window.draw(sprite_sol);
      sprite_sol2.setPosition(sf::Vector2f(918,0));
      sprite_sol3.setPosition(sf::Vector2f(0,714));
      sprite_sol4.setPosition(sf::Vector2f(918,714));
      window.draw(sprite_sol2);
      window.draw(sprite_sol3);
      window.draw(sprite_sol4);
      window.draw(sprite_oeuf);
      window.draw(sprite_chars);
      window.display();
      window.clear();
    }
  return (0);
}
