# click4ever

An auto clicker for Linux running X11. A program that generates a lot of mouse
clicks per second at the current position of the mouse until you move it away.


## Usage

All you have to do is run the program:

	$ click4ever

It will wait for you to make the first click before it starts dispatching mouse
clicks. This gives you time to move the pointer to your desired target. It stops
once you move the mouse again.

If your Desktop Environment supports hotkeys, you can assign a hotkey (WIN+C for
example) to run the program for you.


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

	$ cmake --config Release ..

	$ make install


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
