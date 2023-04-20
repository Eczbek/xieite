# `xieite::console::setCursorAlternative`
Defined in header [`<xieite/console/setCursorAlternative.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/console/setCursorAlternative.hpp)

<br/>

Enables or disables the alternative cursor. The alternative cursor starts at the original cursor's position.

<br/><br/>

## Synopsis

<br/>

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
#include <xieite/console/setCursorAlternative.hpp>

int main() {
	std::cout
		<< xieite::console::setCursorAlternative(true)
		<< "Hello,"
		<< xieite::console::setCursorAlternative(false)
		<< "world!\n";
}
```
Output:
```
world!
```
