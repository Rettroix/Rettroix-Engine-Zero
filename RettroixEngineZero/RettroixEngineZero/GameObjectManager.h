#pragma once
#include "VisibleGameObject.h"

class GameObjectManager
{
public:
  GameObjectManager();
  ~GameObjectManager();

  void Add(std::string name, VisibleGameObject* gameObject);
  void Remove(std::string name);
  int GetObjectCount() const;
  VisibleGameObject* Get(std::string name) const;

  void DrawAll(sf::RenderWindow& renderWindow);
  void UpdateAll();
private:
  //A std::map is made up of a name/value pairs, internally it is composed of a collection of std::pair<> objects.  
  //std::pair<> is just two objects smushed together
  //we want a collection of VisibleGameObject pointers that we are going to access using a std::string as the identifier
  std::map<std::string, VisibleGameObject*> _gameObjects;
  sf::Clock clock;

  struct GameObjectDeallocator
  {
    void operator()(const std::pair<std::string, VisibleGameObject*> & p) const
    {
      delete p.second;
    }
  };
};

//virtual is not used because we don't anyone to inherit from GameObjectManager