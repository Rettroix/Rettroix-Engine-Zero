#include "stdafx.h"
#include "GameObjectManager.h"
#include "Game.h"


GameObjectManager::GameObjectManager()
{
}

GameObjectManager::~GameObjectManager()
{
  //for_each is a method that takes two iterators, one representing where to start, the other representing where to stop and finally it takes a unary function 
  //(meaning it takes a single parameter) that is to be called on each iteration.  
  std::for_each(_gameObjects.begin(), _gameObjects.end(), GameObjectDeallocator());
}

//Our map _gameObjects is literally composed of a collection of std::pair<> objects and in this case all we are doing is adding one more.
void GameObjectManager::Add(std::string name, VisibleGameObject* gameObject)
{
  _gameObjects.insert(std::pair<std::string, VisibleGameObject*>(name, gameObject));
}

//deletes the pointer to the VisibleGameObject* 
void GameObjectManager::Remove(std::string name)
{
  std::map<std::string, VisibleGameObject*>::iterator results = _gameObjects.find(name);
  if (results != _gameObjects.end())
  {
    //second because we want the second part of the pair, (the game object)
    delete results->second;
    _gameObjects.erase(results);
  }
}

//return a game object
VisibleGameObject* GameObjectManager::Get(std::string name) const
{
  std::map<std::string, VisibleGameObject*>::const_iterator results = _gameObjects.find(name);
  if (results == _gameObjects.end())
    return NULL;
  //second because we want the second part of the pair, (the game object)
  return results->second;

}

//returns the number of items contained
int GameObjectManager::GetObjectCount() const
{
  return _gameObjects.size();
}


void GameObjectManager::DrawAll(sf::RenderWindow& renderWindow)
{
  //show mouse coordinates
  cout << "X: " << sf::Mouse::getPosition(renderWindow).x << " Y: " << sf::Mouse::getPosition(renderWindow).y << endl;

  std::map<std::string, VisibleGameObject*>::const_iterator itr = _gameObjects.begin();
  while (itr != _gameObjects.end())
  {
    itr->second->Draw(renderWindow);
    itr++;
  }
}

void GameObjectManager::UpdateAll()
{
  std::map<std::string, VisibleGameObject*>::const_iterator itr = _gameObjects.begin();
  float timeDelta = clock.restart().asSeconds();

  while (itr != _gameObjects.end())
  {
    itr->second->Update(timeDelta);
    itr++;
  }

}