# xieite::console::modes
Declared in `<xieite/console/modes.hpp>`

<br/>

A namespace of console modes.

<br/><br/>

## Definitions
```cpp
constexpr std::string_view showCursor = "\x1b[?25h";
```
```cpp
constexpr std::string_view hideCursor = "\x1b[?25l";
```
```cpp
constexpr std::string_view saveScreen = "\x1b[?47h";
```
```cpp
constexpr std::string_view restoreScreen = "\x1b[?47l";
```
```cpp
constexpr std::string_view enableAlternativeBuffer = "\x1b[?1049h";
```
```cpp
constexpr std::string_view disableAlternativeBuffer = "\x1b[?1049l";
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/console/modes.hpp>

int main() {
	std::cout
		<< "Hello, world!\n"
		<< xieite::console::modes::saveScreen;

	for (int i = 0; i < 10; ++i)
		std::cout << "spam";

	std::cout << xieite::console::modes::restoreScreen;
}
```
Output:
```
Hello, world!
```
