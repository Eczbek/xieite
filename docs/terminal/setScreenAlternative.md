# [xieite](../../README.md)::[terminal](../terminal.md)::setScreenAlternative
Defined in header [<xieite/terminal/setScreenAlternative.hpp>](../../include/xieite/terminal/setScreenAlternative.hpp)

<br/>

Enables or disables the alternative screen

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr std::string setScreenAlternative(bool value) noexcept;
```
### Parameters
- `value` - A `bool` copy to determine whether to save or restore the screen
### Return value
- A `std::string`, the ANSI escape sequence to print

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/terminal/setScreenAlternative.hpp>

int main() {
	std::cout
		<< xieite::terminal::setScreenAlternative(true)
		<< "Hello,"
		<< xieite::terminal::setScreenAlternative(false)
		<< "world!\n";
}
```
Output:
```
world!
```
