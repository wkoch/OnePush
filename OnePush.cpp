/*
  OnePush - v1.0 - November 19, 2014.
  Arduino library for doing many things with a single button.
  Created by William Koch.
  Released into the public domain.
*/

#include "OnePush.h"
#include "../Debounce/Debounce.h"

#define BETWEEN(x, a, b)  ((a) <= (x) && (x) <= (b))

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
  OnePush::update();
  return (_level == 0 ? false : true);
}

byte OnePush::state() {
  OnePush::update();
  return OnePush::status() ? HIGH : LOW;
}

// Returns the current level.
byte OnePush::level() {
  return _level;
}

// Manually sets the level to any value from 0 up to levels.
byte OnePush::set(byte level) {
  if (BETWEEN(level, 0, _levels)) {
    _level = level;
  }
  return _level;
}

// Moves to the next level.
void OnePush::next() {
  _lastCount = OnePush::count();
  _level < _levels ? _level++ : _level = 0;
}
