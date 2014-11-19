# OnePush

Small Arduino library for doing many things with a single button. You can use any button to: turn things on or off with each press, or do different things each press, 4 examples included.

**Tested on an Arduino Due only.**

## Instructions

**This library requires the Debounce library. Just include it, OnePush does the rest.**

Include the libraries in your sketch:

    #include <Debounce.h>
    #include <OnePush.h>

### Constructors

There are two ways to create your OnePush object.

### Single Level Button

This will create an OnePush object with a single level, push the button once to turn somethign ON and push it again to turn it OFF:

    OnePush myButton = OnePush(10); // 10 is the button pin, could be a variable.

### Multi-Level Button

This will create an OnePush object with multiple levels:

    OnePush myButton = OnePush(10, 3); // Button pin 10, 3 levels, plus level 0.

You can have a lot of levels, anything between 1 and 255. Each time you press the button it'll go to the next level. You can do different things for each level. It's something like those older cellphones where you would press the same key several times to cycle through the letters when writing a text message: key 2 cycles the letters *A*, *B* and *C*.

### Functions

OnePush has 6 functions.

#### update()

Reads the debounced button and updates some variables. You probably won't need to use it since most other OnePush functions will call it automatically.

    myButton.update();

#### status()

Returns the current status, false if on Level 0, true on any other level. Good to know if you're on some active level or the default Level 0.

    myButton.status(); // Returns false for Level 0, true otherwise.

#### state()

The same as status(), but returns HIGH/LOW instead of true/false;

    myButton.state(); // Returns LOW for Level 0, HIGH otherwise.

#### level()

Returns the current level. Good for implementing different things for each level.

    (myButton.level() == 2); // Returns true if 2 is the current level, false otherwise.

#### set(level)

Defines the current level, you can change to any valid level, invalid levels will be ignored.

    myButton.set(10); // is ignored if there are not so many levels.
    myButton.set(1); // Changes to Level 1.
    myButton.set(10) == 10; // Returns false since the change wasn't accepted.
    myButton.set(1) == 1; // Changes to Level 1 and returns true.

#### next()

Changes to the next level, changes to Level 0 if the current Level is the last.

    myButton.next(); // Moves from current Level to the next one.
