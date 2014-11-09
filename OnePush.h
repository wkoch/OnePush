/*
  OnePush.cpp - v0.1
  Library for doing many things with a single button.
  Created by William Koch, November 08, 2014.
  Released into the public domain.
*/

#ifndef OnePush_h
#define OnePush_h

#include "Arduino.h"
#include "../Debounce/Debounce.h"

class Debounce;

class OnePush : public Debounce {
  public:
    // Creates an OnePush Object with 1 level.
    // USAGE: OnePush Name(number);
    // OnePush(byte &button) : debounce(&button) {};
    OnePush(byte button);

    // Creates an OnePush Object with custom levels.
    // USAGE: OnePush Name(Number1, Number2);
    OnePush(byte button, byte levels);

    void update();

    // Status and state are only usefull for one-level buttons.
    boolean status(); // Returns False for 0, True for all other levels.
    byte state(); // Returns LOW for 0, HIGH for all other level.

    byte level(); // Returns the current active level.
    byte set(byte number);// Sets the level manually, returns the current level.
    void next(); // Moves to the next level.
  private:
    byte _levels, _level;
    unsigned int _lastCount;
};

#endif
