# xieite::console::getCharacter
Defined in header `<xieite/console/getCharacter.hpp>`

<br/>

Waits for and returns the next keypress input.

<br/><br/>

## Declarations
```cpp
inline char getCharacter(bool echo = false) noexcept;
```

<br/><br/>

## Example
```cpp
#include <chrono>
#include <iostream>
#include <xieite/console/getCharacter.hpp>

int main() {
	std::cout << "Press a key: ";

	std::chrono::time_point start = std::chrono::steady_clock::now();

	char input = xieite::console::getCharacter(true);

	std::chrono::time_point end = std::chrono::steady_clock::now();

	std::cout << "\nElapsed milliseconds: "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(start - end).count() << '\n';
}
```
Possible interaction:
```
Press a key: h
Elapsed milliseconds: 445
```
(I got 445 milliseconds twice while testing this)
