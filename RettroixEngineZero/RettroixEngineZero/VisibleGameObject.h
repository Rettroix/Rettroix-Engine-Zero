#include "stdafx.h"

#pragma once
class VisibleGameObject
{
public:
  //constructor
  VisibleGameObject();
  //destructor
  virtual ~VisibleGameObject();

  virtual void Load(std::string filename);
  virtual void Draw(sf::RenderWindow & window);

  virtual void SetPosition(float x, float y);

private:
  //holds the strite
  sf::Sprite  _sprite;
  //holds the image
  sf::Texture _image;
  //store name of the file loaded
  std::string _filename;
  //check if been loaded to make sure we don't draw an object that hasn't been loaded
  bool _isLoaded;

};
// if you intend for your derived classes to override behavior from the base class, declare your member functions as virtual.