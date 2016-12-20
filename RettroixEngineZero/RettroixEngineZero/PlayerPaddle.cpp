#include "StdAfx.h"
#include "PlayerPaddle.h"
#include "Game.h"

//define default values for _velocity and _maxVelocity
PlayerPaddle::PlayerPaddle() :
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


PlayerPaddle::~PlayerPaddle()
{
}

void PlayerPaddle::Draw(sf::RenderWindow & rw)
{
  VisibleGameObject::Draw(rw);
}

float PlayerPaddle::GetVelocity() const
{
  return _velocity;
}

void PlayerPaddle::Update(float elapsedTime)
{
  //moving left
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    _velocity -= 3.0f;
  }
  //moving right
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    _velocity += 3.0f;
  }
  //brakes
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    _velocity = 0.0f;
  }

  //make sure the velocity doesn't go over max velocity
  if (_velocity > _maxVelocity)
    _velocity = _maxVelocity;

  if (_velocity < -_maxVelocity)
    _velocity = -_maxVelocity;

  //set pos to the current position
  sf::Vector2f pos = this->GetPosition();

  //make sure paddle doesn't go off screen
  if (pos.x  < GetSprite().getLocalBounds().width / 2
    || pos.x >(Game::SCREEN_WIDTH - GetSprite().getLocalBounds().width / 2))
  {
    _velocity = -_velocity; // Bounce by current velocity in opposite direction
  }

  //move the sprite
  GetSprite().move(_velocity * elapsedTime, 0);
}