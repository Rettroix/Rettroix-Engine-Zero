#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "stdafx.h"
struct MenuText
{
public:
  sf::Text text[2];
};

class MainMenu
{

public:
  //define enum type that contains possible menu return types
  enum class MenuResult { Nothing, Exit, Play };
  
  //menu item represents individual menu items in the menu
  struct MenuItem
  {
  public:
    //template represents dimension of menu item
    sf::Rect<int> rect;
    //value to return if menu item is clicked
    MenuResult action;
  };
  MenuText menu;


  MenuResult Show(sf::RenderWindow& window);

private:

  MenuResult GetMenuResponse(sf::RenderWindow& window);
  MenuResult HandleClick(int x, int y);

  std::list<MenuItem> _menuItems;
};

