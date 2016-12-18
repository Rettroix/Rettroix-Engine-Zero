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

void VisibleGameObject::Update(float elapsedTime)
{
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

sf::Vector2f VisibleGameObject::GetPosition() const
{
  if (_isLoaded)
  {
    return _sprite.getPosition();
  }
  return sf::Vector2f();
}

sf::Sprite& VisibleGameObject::GetSprite()
{
  return _sprite;
}

bool VisibleGameObject::IsLoaded() const
{
  return _isLoaded;
}

float VisibleGameObject::GetHeight() const
{
  return _sprite.getLocalBounds().height;
}

float VisibleGameObject::GetWidth() const
{
  return _sprite.getLocalBounds().width;
}

//returns a rectangle that defines the boundaries of our sprite
sf::Rect<float> VisibleGameObject::GetBoundingRect() const
{
  return _sprite.getGlobalBounds();

}