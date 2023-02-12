# xieite::console::getKeyPress
Declared in `<xieite/console/getKeyPress.hpp>`

<br/>

Waits for and returns the next keypress input.

<br/><br/>

## Declaration
```cpp
inline char getKeyPress(const bool echo = false) noexcept;
```

<br/><br/>

## Example
```cpp
#include <chrono> // std::chrono::duration_cast, std::chrono::milliseconds, std::chrono::steady_clock, std::chrono::time_point
#include <iostream> // std::cout
#include <xieite/console/getKeyPress.hpp>

int main() {
	std::cout << "Press a key: ";
	const std::chrono::time_point start = std::chrono::steady_clock::now();
	const char input = xieite::console::getKeyPress(true);
	const std::chrono::time_point end = std::chrono::steady_clock::now();
	std::cout << "\nElapsed milliseconds: " << std::chrono::duration_cast<std::chrono::milliseconds>(start - end).count() << '\n';
}
```
Possible interaction:
```
Press a key: h
Elapsed milliseconds: 445
```
(Fun fact: I got 445 milliseconds twice in a row while testing this)
