
#include "MainMenu.h"
#include "ServiceLocator.h"



MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{

  //Load menu image from file
  sf::Texture image;
  image.loadFromFile("images/mainmenu.png");
  sf::Sprite sprite(image);

  //Setup clickable regions

  //Play menu item coordinates
  MenuItem playButton;
  //define the location of the rect
  playButton.rect = sf::Rect<int>(0, 145, 1023, 235);
  //define the action type of the menu item
  playButton.action = MenuResult::Play;

  //Exit menu item coordinates
  MenuItem exitButton;
  //define the location of the rect
  exitButton.rect = sf::Rect<int>(0, 383, 1023, 177);
  //define the action type of the menu item
  exitButton.action = MenuResult::Exit;

  //add play button to end of list
  _menuItems.push_back(playButton);
  //add exit button to end of list
  _menuItems.push_back(exitButton);

  //draw and display menu
  window.draw(sprite);
  window.display();

  return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
  //declare iterator
  std::list<MenuItem>::iterator it;

  //iterator asigned first item in the list
  //ends when the iterator hasn't hit the end
  //iterator is incremented
  for (it = _menuItems.begin(); it != _menuItems.end(); it++)
  {
    sf::Rect<int> menuItemRect = (*it).rect;
    if (menuItemRect.contains(x, y)) 
    {
      return (*it).action;
    }
  }

  return MenuResult::Nothing;
}

//event loop for the menu
MainMenu::MenuResult  MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
  sf::Event menuEvent;

  //infinite loop
  while (42 != 43)
  {

    while (window.pollEvent(menuEvent))
    {
      if (menuEvent.type == sf::Event::MouseButtonPressed)
      {
        if (ServiceLocator::GetAudio()->IsSongPlaying())
          ServiceLocator::GetAudio()->StopAllSounds();
        return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
      }
      if (menuEvent.type == sf::Event::Closed)
      {
        return MenuResult::Exit;
      }
    }
  }
}