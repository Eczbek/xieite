# `xieite::console::getCharacter`
Defined in header [`<xieite/console/getCharacter.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/console/getCharacter.hpp)

<br/>

Waits for and returns the next keypress input.

<br/><br/>

## Synopsis

<br/>

```cpp
inline char getCharacter(bool echo = false) noexcept;
```
### Parameters
- `echo` - A `bool` copy, set to `false` by default. Determines whether to allow an echo when a character is input
### Return value
- `char` - The input character

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/console/getCharacter.hpp>
#include <xieite/console/putBackString.hpp>

int main() {
	std::cin.putback('h');

	std::cout << xieite::console::getCharacter() << '\n';
}
```
Output:
```
h
```
