#pragma once
#include "stdafx.h"
#include "PlayerPaddle.h"
#include "GameObjectManager.h"
#include "ServiceLocator.h"
#include "SFMLSoundProvider.h"
class Game
{

public:
  //get's the game started
  static void Start();
  static sf::RenderWindow& GetWindow();
  const static sf::Event& GetInput();
  const static GameObjectManager& GetGameObjectManager();

  const static int SCREEN_WIDTH = 1280;
  const static int SCREEN_HEIGHT = 720;
private:
  static bool IsExiting();
  static void GameLoop();

  static void ShowSplashScreen();
  static void ShowMenu();
  //The states the game can be in
  enum class GameState
  {
    Uninitialized, ShowingSplash, Paused,
    ShowingMenu, Playing, Exiting
  };

  static GameState _gameState;
  static sf::RenderWindow _mainWindow;
  //the object manager
  static GameObjectManager _gameObjectManager;
};
//Members of this class are static
//no matter how many static objects of the class are created, there 
//is only one copy of the static member
//static methods can only access static member variables