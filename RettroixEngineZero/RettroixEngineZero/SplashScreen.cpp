#include "StdAfx.h"
#include "SplashScreen.h"


void SplashScreen::Show(sf::RenderWindow & renderWindow)
{
  //create texture called image
  sf::Texture image;
  //load texture from file and if it's not there return
  if (image.loadFromFile("images/SplashScreen.png") != true)
  {
    return;
  }

  //create a sprite of the image as you need to make it a sprite
  //to actually see it
  sf::Sprite sprite(image);

  //draw the sprite
  renderWindow.draw(sprite);
  //display it on screen
  renderWindow.display();

  sf::Event event;
  //infinite loop
  while (true)
  {
    //each pass through we check for events
    while (renderWindow.pollEvent(event))
    {
      //if one of these events happen the splash screen closes
      if (event.type == sf::Event::EventType::KeyPressed
        || event.type == sf::Event::EventType::MouseButtonPressed
        || event.type == sf::Event::EventType::Closed)
      {
        return;
      }
    }
  }
}