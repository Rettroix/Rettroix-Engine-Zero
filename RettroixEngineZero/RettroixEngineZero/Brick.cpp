#include "StdAfx.h"
#include "Brick.h"
#include "Game.h"

//define default values for _velocity and _maxVelocity
Brick::Brick() :
  _velocity(0),
  _maxVelocity(300.0f)
{
  //Load the image file / sprite data within the constructor
  Load("images/brick.png");
  //An assert simply evaluates that a given expression is true
  assert(IsLoaded());
  //This makes the sprite position it’s center point instead of the default top left corner.
  GetSprite().setOrigin(GetSprite().getScale().x / 2, GetSprite().getScale().y / 2);

}


Brick::~Brick()
{
}

void Brick::Draw(sf::RenderWindow & rw)
{
  VisibleGameObject::Draw(rw);
}

float Brick::GetVelocity() const
{
  return _velocity;
}

void Brick::Update(float elapsedTime)
{


}