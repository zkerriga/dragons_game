# dragons_game
A console mini-game that demonstrates the capabilities of <a href="https://en.wikipedia.org/wiki/Object-oriented_programming">object-oriented programming</a> in C.

### Usage:
Inside the `main.c` file, there are two functions that form a team of <b>dragons</b> and a team of <b>heroes</b>. The command can be typed from all available class constructors, passing the necessary characteristics for initialization.
Run the `make` command at the root of the project. And then run the program itself: `./dragons_game`.

### Description of the game's progress:
The game has a <b>Battlefield</b> class that receives a list of <b>heroes</b> and a list of <b>dragons</b>. A single array is randomly generated from two lists. <b>Battlefield</b> pushes two <b>units</b> together until only one class is left alive.
At the end of the battle, use the <b>Battlefield</b><i>->end()</i> method to output information about the winner.

### Also:
At the moment, <i>inheritance</i> is not fully implemented, which is why there is a repetition of the code. This will be improved in future versions!
