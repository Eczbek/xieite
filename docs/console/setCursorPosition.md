# `xieite::console::setCursorPosition`
Defined in header [`<xieite/console/setCursorPosition.hpp>`](../../include/xieite/console/setCursorPosition.hpp)

<br/>

Sets the terminal cursor's position.

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr std::string setCursorPosition(xieite::console::Position position) noexcept;
```
### Parameters
- `position` - A `xieite::console::Position` copy, the new cursor coordinates
### Return value
- `std::string` - The resulting ANSI escape sequence to print

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/console/setPosition.hpp>

int main() {
	std::cout
		<< xieite::console::setCursorPosition({ 2, 5 })
		<< "Hello, world!\n";
}
```
Possible output:
```


     Hello, world!
```

<br/><br/>

## See also
- [`xieite::console::Position`](../../docs/console/Position.md)
