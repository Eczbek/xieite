# [`xieite`](../../README.md)`::`[`terminal`](../../docs/terminal.md)`::setCursorPosition`
Defined in header [`<xieite/terminal/setCursorPosition.hpp>`](../../include/xieite/terminal/setCursorPosition.hpp)

<br/>

Sets the terminal cursor's position.

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr std::string setCursorPosition(xieite::terminal::Position position) noexcept;
```
### Parameters
- `position` - A `xieite::terminal::Position` copy, the new cursor coordinates
### Return value
- `std::string` - The resulting ANSI escape sequence to print

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/terminal/setPosition.hpp>

int main() {
	std::cout
		<< xieite::terminal::setCursorPosition({ 2, 5 })
		<< "Hello, world!\n";
}
```
Possible output:
```


     Hello, world!
```

<br/><br/>

## See also
- [`xieite::terminal::Position`](../../docs/terminal/Position.md)
