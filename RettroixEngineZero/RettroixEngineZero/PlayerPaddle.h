#pragma once
#include "VisibleGameObject.h"

class PlayerPaddle :
  public VisibleGameObject
{
public:
  PlayerPaddle();
  ~PlayerPaddle();

  //declare that we are going to override Update() from our base class
  void Update(float elapsedTime);
  void Draw(sf::RenderWindow& rw);

  float GetVelocity() const;

private:
  float _velocity;  // -- left ++ right
  float _maxVelocity;
};
