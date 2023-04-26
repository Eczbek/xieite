# [`xieite`](../../README.md)`::`[`console`](../../docs/console.md)`::getCharacter`
Defined in header [`<xieite/console/getCharacter.hpp>`](../../include/xieite/console/getCharacter.hpp)

<br/>

Waits for and returns the next keypress input.

<br/><br/>

## Synopsis

<br/>

```cpp
inline char getCharacter(bool blocking = true) noexcept;
```
### Parameters
- `blocking` - A `bool` copy, set to `true` by default. Determines whether to block the thread while waiting for input or return immediately if there is none
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
