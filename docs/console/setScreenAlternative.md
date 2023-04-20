# `xieite::console::setScreenAlternative`
Defined in header [`<xieite/console/setScreenAlternative.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/console/setScreenAlternative.hpp)

<br/>

Enables or disables the alternative screen.

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
#include <xieite/console/setScreenAlternative.hpp>

int main() {
	std::cout
		<< xieite::console::setScreenAlternative(true)
		<< "Hello,"
		<< xieite::console::setScreenAlternative(false)
		<< "world!\n";
}
```
Output:
```
world!
```
