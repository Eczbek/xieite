# [`xieite`](../../README.md)`::`[`console`](../../docs/console.md)`::getCharacter`
Defined in header [`<xieite/console/getCharacter.hpp>`](../../include/xieite/console/getCharacter.hpp)

<br/>

Waits for and returns the next keypress input.

<br/><br/>

## Synopsis

<br/>

```cpp
inline char getCharacter(const xieite::console::ModeLock& modeLock);
```
### Parameters
- `modeLock` - A `xieite::console::ModeLock` constant reference to apply while getting input
### Return value
- `char` - The input character

<br/>

```cpp
inline char getCharacter();
```
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
