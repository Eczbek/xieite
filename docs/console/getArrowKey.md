# `xieite::console::getArrowKey`
Defined in header [`<xieite/console/getArrowKey.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/console/getArrowKey.hpp)

<br/>

Waits for an arrow key input and immediately returns its direction as a relative `xieite::console::Position`.

<br/><br/>

## Synopsis

<br/>

```cpp
inline xieite::console::Position getArrowKey(bool echo = false) noexcept;
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
#include <xieite/console/getArrowKey.hpp>
#include <xieite/console/putBackString.hpp>

int main() {
	xieite::console::putBackString("\u001b[B"); // Down arrow

	xieite::console::Position direction = xieite::console::getArrowKey();

	std::cout << '(' << direction.row << ", " << direction.column << ")\n";
}
```
Output:
```
(0, 1)
```

<br/><br/>

## See also
- [`xieite::console::Position`](https://github.com/Eczbek/xieite/tree/main/docs/console/Position.md)
