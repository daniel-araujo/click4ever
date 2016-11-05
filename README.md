# Click4Ever

A tool that simulates multiple mouse clicks quickly in succession for Linux.


## Usage

You start by running the following command:

	$ click4ever

Now the program is waiting for you to make the first click. After clicking, it will start dispatching mouse clicks in succession forever until you move the mouse away.


## Installation

Simply run the following commands:

	$ ./configure

	$ make

	$ make install

The first command will check if your system has the needed functionalities
available for this to work. If it reports that something is missing, you most
likely just need to install something on your system. The second command will
compile the program. The third and last one will install the program on your
system. You will probably need higher privileges to install something on the
system.

To change how the program is compiled and installed, see the options you have
available by running `./configure -h`.


## Contributing

Found a bug or want to contribute code? Feel free to create an issue or send a
pull request on GitHub [[1]].


## License

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

[1]: https://github.com/daniel-araujo/click4ever
