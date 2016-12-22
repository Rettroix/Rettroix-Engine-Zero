#pragma once
#include "VisibleGameObject.h"

class RectangleObject :
  public VisibleGameObject
{
public:
  RectangleObject();
  ~RectangleObject();
  void Initialise(float xSize, float ySize, float xPos, float yPos);
  //declare that we are going to override Update() from our base class
  void Update(float elapsedTime);
  void Draw(sf::RenderWindow& rw);

  float GetVelocity() const;

private:
  float _velocity;  
  float _maxVelocity;

};
sf::RectangleShape Rectangle(sf::Vector2f(0, 0));
