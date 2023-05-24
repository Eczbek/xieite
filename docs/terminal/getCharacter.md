# [`xieite`](../../README.md)`::`[`terminal`](../../docs/terminal.md)`::getCharacter`
Defined in header [`<xieite/terminal/getCharacter.hpp>`](../../include/xieite/terminal/getCharacter.hpp)

<br/>

Waits for and returns the next keypress input.

<br/><br/>

## Synopsis

<br/>

```cpp
inline char getCharacter(const xieite::terminal::ModeLock& modeLock);
```
### Parameters
- `modeLock` - A `xieite::terminal::ModeLock` constant reference to apply while getting input
### Return value
- `char` - The input character

<br/><br/>

```cpp
inline char getCharacter();
```
### Return value
- `char` - The input character

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/terminal/getCharacter.hpp>
#include <xieite/terminal/putBackString.hpp>

int main() {
	std::cin.putback('h');

	std::cout << xieite::terminal::getCharacter() << '\n';
}
```
Output:
```
h
```