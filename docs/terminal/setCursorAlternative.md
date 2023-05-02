# [`xieite`](../../README.md)`::`[`terminal`](../../docs/terminal.md)`::setCursorAlternative`
Defined in header [`<xieite/terminal/setCursorAlternative.hpp>`](../../include/xieite/terminal/setCursorAlternative.hpp)

<br/>

Enables or disables the alternative cursor. The alternative cursor starts at the original cursor's position.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
constexpr std::string setCursorAlternative(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to enable or disable the alternative cursor
### Return value
- A `std::string`, the ANSI escape sequence to print

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/terminal/setCursorAlternative.hpp>

int main() {
	std::cout
		<< xieite::terminal::setCursorAlternative(true)
		<< "Hello,"
		<< xieite::terminal::setCursorAlternative(false)
		<< "world!\n";
}
```
Output:
```
world!
```
