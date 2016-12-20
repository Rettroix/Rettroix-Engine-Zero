#pragma once

#include "stdafx.h"

class IAudioProvider
{
public:
  virtual ~IAudioProvider() {}
  virtual void PlaySound(std::string filename) = 0;
  virtual void PlaySong(std::string filename, bool looping) = 0;
  virtual void StopAllSounds() = 0;

  virtual bool IsSoundPlaying() = 0;
  virtual bool IsSongPlaying() = 0;
};

//

//By naming convention a class prefixed with “I” represents
//an interface.In C# or Java this is an actual thing, while in C++ 
//it’s something generally called an “abstract base class”, which 
//means it is a class with one or more pure virtual methods.

//When you declare a pure virtual method, you are simply defining 
//a function definition that MUST be implemented in derived class.
//You can’t actually create classes that contain a pure virtual method,
//if you try to new one, you will get a compiler error.Instead you 
//inherit from that class and create the inherited class instead.
//This forced inheritance provides a common interface and thus the name.