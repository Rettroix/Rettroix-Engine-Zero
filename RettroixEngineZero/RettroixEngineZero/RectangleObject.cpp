#include "StdAfx.h"
#include "RectangleObject.h"
#include "Game.h"

//define default values for _velocity and _maxVelocity
RectangleObject::RectangleObject() :
  _velocity(0),
  _maxVelocity(300.0f)
{
  //Load the image file / sprite data within the constructor
  Load("images/paddle.png");
  //An assert simply evaluates that a given expression is true
  assert(IsLoaded());
  //This makes the sprite position it’s center point instead of the default top left corner.
  GetSprite().setOrigin(GetSprite().getScale().x / 2, GetSprite().getScale().y / 2);

}


RectangleObject::~RectangleObject()
{
}

void RectangleObject::Initialise(float xSize, float ySize, float xPos, float yPos)
{
  Rectangle.setSize(sf::Vector2f(xSize, ySize));
  Rectangle.setPosition((xPos), (yPos));

}

void RectangleObject::Draw(sf::RenderWindow & rw)
{
  VisibleGameObject::Draw(rw);
}

float RectangleObject::GetVelocity() const
{
  return _velocity;
}

void RectangleObject::Update(float elapsedTime)
{
  
}