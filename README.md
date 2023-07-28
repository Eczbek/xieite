# **XIEITE**
C++ header-only utility library

The goal of this project is to extend the standard library and to provide an organized collection of components that can be included easily in projects without any external dependencies

<br/>

## Usage
Copy the `include` directory's contents into your project

<br/>

## Support
- Linux: 100%
- macOS: Should work
- Windows: *ish*

<br/>

## [Documentation](https://github.com/Eczbek/xieite/tree/main/docs/xieite.md)

<br/>

## Examples
```cpp
// Simple canvas
// - Select pens with keys 0-9
// - Space to start or stop drawing
// - Move cursor with WASD
// - Press Q to quit

#include <chrono>
#include <iostream>
#include <thread>
#include <xieite/strings/toLower.hpp>
#include <xieite/system/BufferPosition.hpp>
#include <xieite/system/terminal.hpp>

int main() {
	xieite::system::terminal.setInputEcho(false);
	xieite::system::terminal.setInputSignals(false);
	xieite::system::terminal.setScreenAlternative(true);

	char pen = '#';
	bool draw = false;
	bool running = true;

	while (running) {
		for (const char input : xieite::strings::toLower(xieite::system::terminal.readString())) {
			if ((input >= '0') && (input <= '9')) {
				pen = " .:-=+*#%@"[input - '0'];
			} else {
				switch (input) {
				case ' ':
					draw = !draw;
					break;

				case 'w':
					xieite::system::terminal.moveCursorPosition(xieite::system::BufferPosition(0, -1));
					break;

				case 'a':
					xieite::system::terminal.moveCursorPosition(xieite::system::BufferPosition(-1, 0));
					break;

				case 's':
					xieite::system::terminal.moveCursorPosition(xieite::system::BufferPosition(0, 1));
					break;

				case 'd':
					xieite::system::terminal.moveCursorPosition(xieite::system::BufferPosition(1, 0));
					break;

				case 'q':
					running = false;
					break;
				}

				if (draw) {
					std::cout << pen;
					xieite::system::terminal.moveCursorPosition(xieite::system::BufferPosition(-1, 0));
				}
			}
		}

		std::cout.flush();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	xieite::system::terminal.setScreenAlternative(false);
}
```
```cpp
// ...
```
