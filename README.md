# click4ever

An auto clicker for Linux running X11. Generates mouse clicks at a specified
location. Can pause when moving away and resume when going back.


## Usage

Running the program with no options:

	$ click4ever

Waits for you to make the first click before it dispatches mouse clicks.
This gives you time to move the pointer to your desired location. The program
stops once you move the pointer away.

If your Desktop Environment supports hotkeys, you can assign a hotkey (WIN+C for
example) to run the program for you.

You can have it pause instead of exiting the program:

	$ click4ever --on-leave-area=pause --area=10

This will stop clicking when the pointer leaves the area around the first click. It will resume clicking when the pointer returns to the area. You will have to manually stop the program.

You can choose which button to press:

	$ click4ever --button=middle

Set a delay, in milliseconds, between clicks:

	$ click4ever --delay=10

For more options run:

	$ click4ever --help


## Installation

### Arch Linux

You can find it in the AUR

```
https://aur.archlinux.org/packages/click4ever/
```

### Source

You will need to have `cmake`, `boost` and `xdotool` installed.

You can compile and install this program with the following commands:

	$ mkdir build

	$ cd build

	$ cmake -DCMAKE_BUILD_TYPE=Release ..

	$ make install


## Changelog

### 1.3.0 (2023-03-26)

- Added `--on-leave-area`: the action to perform on leaving the click area.
- Added `--area`: the amount of pixels you can move before it performs the on-leave-area action.


## Contributing

The easiest way to contribute is by starring this project on GitHub!

https://github.com/daniel-araujo/click4ever

Found a bug or want to contribute code? Feel free to create an issue or send a
pull request on GitHub:

https://github.com/daniel-araujo/click4ever/issues


## License

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
