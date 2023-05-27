# [xieite](../../README.md)::[strings](../strings.md)::repeat
Defined in header [<xieite/strings/repeat.hpp>](../../include/xieite/strings/repeat.hpp)

<br/>

Repeats a string

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr std::string repeat(std::string_view string, std::size_t count) noexcept;
```
### Parameters
- `string` - A `std::string_view` copy, the value to repeat
- `count` - A `std::size_t` copy, how many times to repeat string
### Return value
- A `std::string`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/strings/repeat.hpp>

int main() {
	std::cout << xieite::strings::repeat("Hello, world!\n", 3);
}
```
Output:
```
Hello, world!
Hello, world!
Hello, world!
```
