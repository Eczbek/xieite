# xieite::console::nextKeyPress
Declared in `<xieite/console/nextKeyPress.hpp>`

<br/>

Waits for and returns the next keypress input.

<br/><br/>

## Declaration
```cpp
char nextKeyPress(const bool echo = false) noexcept;
```

<br/><br/>

## Example
```cpp
#include <chrono>
#include <iostream>
#include <xieite/console/nextKeyPress.hpp>

int main() {
	std::cout << "Press a key: ";
	const std::chrono::time_point start = std::chrono::steady_clock::now();
	const char input = xieite::console::nextKeyPress(true);
	const std::chrono::time_point end = std::chrono::steady_clock::now();
	std::cout << "\nElapsed milliseconds: " << std::chrono::duration_cast<std::chrono::milliseconds>(start - end).count() << '\n';
}
```
Possible interaction:
```
Press a key: h
Elapsed milliseconds: 445
```
