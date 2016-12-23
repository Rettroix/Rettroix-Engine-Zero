
#include "MainMenu.h"
#include "ServiceLocator.h"
using namespace std;



MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{
  
  image.loadFromFile("images/sky.png");
  sprite.setTexture(image);

  //Setup clickable regions

  //text
  sf::Font font;

  if (!font.loadFromFile("arial.ttf"))
  {
    // handle error
  }
  menu.text[0].setFont(font);
  menu.text[0].setString("Play Game");
  menu.text[0].setCharacterSize(40);
  menu.text[0].setPosition(100,100);

  menu.text[1].setFont(font);
  menu.text[1].setString("Exit");
  menu.text[1].setColor(sf::Color::White);
  menu.text[1].setCharacterSize(40);
  menu.text[1].setPosition(100, 200);

  //Play menu item coordinates
  MenuItem playButton;
  //define the location of the rect
  playButton.rect = sf::Rect<int>(100, 110, 30, 100);
  //define the action type of the menu item
  playButton.action = MenuResult::Play;
  sf::RectangleShape playRectangle(sf::Vector2f(200, 40));
  playRectangle.setSize(sf::Vector2f(400, 67));
  //Exit menu item coordinates
  MenuItem exitButton;
  //define the location of the rect
  exitButton.rect = sf::Rect<int>(100, 200, 200, 100);
  //define the action type of the menu item
  exitButton.action = MenuResult::Exit;

  //add play button to end of list
  _menuItems.push_back(playButton);
  //add exit button to end of list
  _menuItems.push_back(exitButton);

  //draw and display menu
  window.draw(menu.text[0]);
  window.draw(menu.text[1]);
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
  //Load menu image from file

  //infinite loop
  while (42 != 43)
  {

    cout << sf::Mouse::getPosition(window).x << endl;

    window.clear(sf::Color(0, 0, 0));
    window.draw(sprite);

    //mouse over play button
    if (sf::Mouse::getPosition(window).x > 100 && sf::Mouse::getPosition(window).x < 300 &&
      sf::Mouse::getPosition(window).y > 115 && sf::Mouse::getPosition(window).y < 145)
    {
      menu.text[0].setColor(sf::Color::Blue);
      window.draw(menu.text[0]);
      if (menuEvent.type == sf::Event::MouseButtonPressed)
      {
        return MenuResult::Play;

      }
    }
    else
    {
      menu.text[0].setColor(sf::Color::White);
      window.draw(menu.text[0]);

    }
    //mouse over exit
    if (sf::Mouse::getPosition(window).x > 100 && sf::Mouse::getPosition(window).x < 300 &&
      sf::Mouse::getPosition(window).y > 200 && sf::Mouse::getPosition(window).y < 240)
    {
      menu.text[1].setColor(sf::Color::Blue);
      window.draw(menu.text[1]);
      if (menuEvent.type == sf::Event::MouseButtonPressed)
      {
        return MenuResult::Exit;

      }
    }
    else
    {
      menu.text[1].setColor(sf::Color::White);
      window.draw(menu.text[1]);

    }
    while (window.pollEvent(menuEvent)) 
    {
     
      //if (menuEvent.type == sf::Event::MouseButtonPressed)
      //{
      //  if (ServiceLocator::GetAudio()->IsSongPlaying())
      //    ServiceLocator::GetAudio()->StopAllSounds();
      //  return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
      //}
      if (menuEvent.type == sf::Event::Closed)
      {
        return MenuResult::Exit;
      }
    }
    window.display();
  }

}