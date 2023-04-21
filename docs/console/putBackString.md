# `xieite::console::putBackString`
Defined in header [`<xieite/console/putBackString.hpp>`](../../include/xieite/console/putBackString.hpp)

<br/>

Puts a string back into the input buffer.

<br/><br/>

## Synopsis

<br/>

```cpp
inline void putBackString(std::string_view value) noexcept;
```
### Parameters
- `value` - A `std::string_view` copy to add to the buffer.

<br/><br/>

## Example
```cpp
#include <iostream>
#include <string>
#include <xieite/console/putBackString.hpp>

int main() {
	xieite::console::putBackString("Hello, world!\n");

	std::string input;

	std::getline(std::cin, input);

	std::cout << input << '\n';
}
```
Output:
```
Hello, world!
```
