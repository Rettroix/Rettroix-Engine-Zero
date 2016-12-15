#include "VisibleGameObject.h"


VisibleGameObject::VisibleGameObject()
{
  _isLoaded = false;
}


VisibleGameObject::~VisibleGameObject()
{
}

void VisibleGameObject::Load(std::string filename)
{
  //if loading image to file fails is loaded becomes false
  if (_image.loadFromFile(filename) == false)
  {
    _filename = "";
    _isLoaded = false;
  }
  else
  {
    //otherwise it's successful and set the sprite
    _filename = filename;
    _sprite.setTexture(_image);
    _isLoaded = true;
  }
}

void VisibleGameObject::Draw(sf::RenderWindow & renderWindow)
{
  //checks if been loaded and if it has draws sprite to render
  //window
  if (_isLoaded)
  {
    renderWindow.draw(_sprite);
  }
}

void VisibleGameObject::SetPosition(float x, float y)
{
  //check if image has been loaded then set sprites
  //position based on inputted data
  if (_isLoaded)
  {
    _sprite.setPosition(x, y);
  }
}