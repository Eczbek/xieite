# [`xieite`](../../README.md)`::`[`terminal`](../../docs/terminal.md)`::getArrowDirection`
Defined in header [`<xieite/terminal/getArrowDirection.hpp>`](../../include/xieite/terminal/getArrowDirection.hpp)

<br/>

Waits for an arrow key input and immediately returns its direction as a relative `xieite::terminal::Position`.

<br/><br/>

## Synopsis

<br/>

```cpp
inline xieite::terminal::Position getArrowDirection(const xieite::terminal::ModeLock& modeLock);
```
### Parameters
- `modeLock` - A `xieite::terminal::ModeLock` constant reference to apply while getting input
### Return value
- A `xieite::terminal::Position`, the arrow key's direction represented as one of four cardinal directions or `{ 0, 0 }` if the input is not a valid arrow key code

<br/>

```cpp
inline xieite::terminal::Position getArrowDirection();
```
### Return value
- A `xieite::terminal::Position`, the arrow key's direction

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/terminal/Position.hpp>
#include <xieite/terminal/getArrowDirection.hpp>
#include <xieite/terminal/putBackString.hpp>

int main() {
	xieite::terminal::putBackString("\u001b[B"); // Down arrow

	xieite::terminal::Position direction = xieite::terminal::getArrowDirection();

	std::cout << '(' << direction.row << ", " << direction.column << ")\n";
}
```
Output:
```
(0, 1)
```

<br/><br/>

## See also
- [`xieite::terminal::ModeLock`](../../docs/terminal/ModeLock.md)
- [`xieite::terminal::Position`](../../docs/terminal/Position.md)
