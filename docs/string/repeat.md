# `xieite::string::repeat`
Defined in header [`<xieite/string/repeat.hpp>`](../../include/xieite/string/repeat.hpp)

<br/>

Repeats a string.

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr std::string repeat(std::string_view string, std::size_t count) noexcept;
```
### Parameters
- `string` - A `std::string_view` copy, the value to repeat
- `count` - A `std::size_t` copy, how many times to repeat `string`
### Return value
- A `std::string`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/string/repeat.hpp>

int main() {
	std::cout << xieite::string::repeat("Hello, world!\n", 3);
}
```
Output:
```
Hello, world!
Hello, world!
Hello, world!
```
