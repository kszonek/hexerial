# hexerial

Simple command line tool to monitor serial traffic, features:
- hexadecimal view of data
- read-only mode

## Build

![Ubuntu](https://github.com/kszonek/hexerial/workflows/Ubuntu/badge.svg)

Prerequisites:
- cmake
- g++

Building under GNU/Linux:

```
$ cd build
$ cmake ..
$ make
$ sudo make install
```

## Usage:
```
Hexerial v1.0
Usage: 
	-b [value]	set baudrate (default: 9600)
	-c [value]	number of columns (default: 8)
	-h		show this help dialog
	-p [value]	set serial port path (default: /dev/ttyUSB0)
	-v		verbose mode
```

## License

Software is released under GNU General Public License v3.0, see LICENSE file.
