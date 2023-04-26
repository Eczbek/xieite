# [`xieite`](../../README.md)`::`[`console`](../../docs/console.md)`::getArrowDirection`
Defined in header [`<xieite/console/getArrowDirection.hpp>`](../../include/xieite/console/getArrowDirection.hpp)

<br/>

Waits for an arrow key input and immediately returns its direction as a relative `xieite::console::Position`.

<br/><br/>

## Synopsis

<br/>

```cpp
inline xieite::console::Position getArrowDirection(bool echo = false) noexcept;
```
### Parameters
- `echo` - A `bool` copy to specify if echoing should be enabled while waiting for input
### Return value
- A `xieite::console::Position`, the arrow key's direction represented as one of four cardinal directions or `{ 0, 0 }` if the input is not a valid arrow key code

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/console/Position.hpp>
#include <xieite/console/getArrowDirection.hpp>
#include <xieite/console/putBackString.hpp>

int main() {
	xieite::console::putBackString("\u001b[B"); // Down arrow

	xieite::console::Position direction = xieite::console::getArrowDirection();

	std::cout << '(' << direction.row << ", " << direction.column << ")\n";
}
```
Output:
```
(0, 1)
```

<br/><br/>

## See also
- [`xieite::console::Position`](../../docs/console/Position.md)
