/*
  OnePush.cpp - v1.0 - November 09, 2014.
  Library for doing many things with a single button.
  Created by William Koch.
  Released into the public domain.
*/

#include "OnePush.h"
#include "../Debounce/Debounce.h"

// Creates an OnePush Object with 1 level.
OnePush::OnePush(byte button)  : Debounce(button) {
  _levels = 1;
  _level = 0;
  _lastCount = OnePush::count();
}

// Creates an OnePush Object with custom levels.
OnePush::OnePush(byte button, byte levels) : Debounce(button){
  _levels = levels;
  _level = 0;
  _lastCount = OnePush::count();
}

// Updates everything
void OnePush::update() {
  OnePush::read();
  if (OnePush::count() != _lastCount) {
    OnePush::next();
  }
}

// Returns the current status, false for level 0, true otherwise.
boolean OnePush::status() {
  return (_level == 0 ? false : true);
}

byte OnePush::state() {
  return OnePush::status() ? HIGH : LOW;
}

// Returns the current level.
byte OnePush::level() {
  return _level;
}

// Manually sets the level to any value from 0 up to levels.
byte OnePush::set(byte number) {
  number <= _levels ? _level = number : 0 ;
  return _level;
}

// Moves to the next level.
void OnePush::next() {
  _lastCount = OnePush::count();
  _level < _levels ? _level++ : _level = 0;
}
