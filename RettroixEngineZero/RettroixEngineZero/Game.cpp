#include "Game.h"



void Game::Start(void)
{
  //The game state should start uninitialized so return if it is  
  if (_gameState != GameState::Uninitialized)
  {
    return;
  }

  //create a window of resolution 1280x720 at 32bpp colour
  _mainWindow.create(sf::VideoMode(1280, 720, 32), "Rettroix Engine Zero");
  //Switch the game to playing state
  _gameState = Game::GameState::Playing;

  //start the game loop forever untill isExiting is called
  while (!IsExiting())
  {
    //call game loop while not exiting
    GameLoop();
  }
  //close main window when out the loop
  _mainWindow.close();
}

bool Game::IsExiting()
{
  //if the game state is exiting then return true
  if (_gameState == Game::GameState::Exiting)
    return true;
  else
    return false;
}

void Game::GameLoop()
{
  sf::Event currentEvent;
  while (_mainWindow.pollEvent(currentEvent))
  {
    //do things based on current game state
    switch (_gameState)
    {
      //when playing
    case Game::GameState::Playing:
    {
      //clear the screen to red
      _mainWindow.clear(sf::Color(255, 0, 0));
      //then display it
      _mainWindow.display();

      //if the current event is closed
      if (currentEvent.type == sf::Event::Closed)
      {
        //then change the state to exiting
        _gameState = Game::GameState::Exiting;
      }
      break;
    }
    }
  }
}

//Are static so need to be instanced manually

//when Game is created, its _gameState value will start as unitialized
Game::GameState Game::_gameState = GameState::Uninitialized;
sf::RenderWindow Game::_mainWindow;