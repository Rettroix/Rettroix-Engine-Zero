#include "Game.h"
#include "SplashScreen.h"
#include "MainMenu.h"
void Game::Start(void)
{
  //The game state should start uninitialized so return if it is  
  if (_gameState != GameState::Uninitialized)
  {
    return;
  }

  //create a window of resolution 1280x720 at 32bpp colour
  _mainWindow.create(sf::VideoMode(1280, 720, 32), "Rettroix Engine Zero");
  //load the players images and positions
  _player1.Load("images/paddle.png");
  _player1.SetPosition((1280 / 2) - 45, 700);
  //when game starts show splash screen
  _gameState = Game::GameState::ShowingSplash;

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
    case Game::GameState::ShowingMenu:
    {
      ShowMenu();
      break;
    }
    case Game::GameState::ShowingSplash:
    {
      ShowSplashScreen();
      break;
    }
      //when playing
    case Game::GameState::Playing:
    {
      //clear the screen to black
      _mainWindow.clear(sf::Color(0, 0, 0));
      //draw the player to screen
      _player1.Draw(_mainWindow);
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

void Game::ShowSplashScreen()
{
  //creates a splashscreen object
  SplashScreen splashScreen;
  //calls the show method
  splashScreen.Show(_mainWindow);
  //change state when splashscreen has ended
  _gameState = Game::GameState::ShowingMenu;
}

void Game::ShowMenu()
{
  //create main menu object
  MainMenu mainMenu;
  MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
  switch (result)
    {
    case MainMenu::MenuResult::Exit:
      _gameState = Game::GameState::Exiting;
      break;
    case MainMenu::MenuResult::Play:
      _gameState = Game::GameState::Playing;
      break;
     }
 }

//Are static so need to be instanced manually

//when Game is created, its _gameState value will start as unitialized
Game::GameState Game::_gameState = GameState::Uninitialized;
sf::RenderWindow Game::_mainWindow;
//because _player1 is a static member variable, it needs to be instantiated in the global namespace
PlayerPaddle Game::_player1;