# `xieite::string::toUppercase`
Defined in header [`<xieite/string/toUppercase.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/string/toUppercase.hpp)

<br/>

Converts a string or character to uppercase. Only handles characters `a` to `z`.

<br/><br/>

## Synopses

<br/>

```cpp
constexpr char toUppercase(char character) noexcept;
```
### Parameters
- `character` - A `char` copy
### Return value
- A `char`

<br/>

```cpp
constexpr std::string toUppercase(std::string string) noexcept;
```
### Parameters
- `string` - A `std::string` copy
### Return value
- A `std::string`

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/string/toUppercase.hpp>

int main() {
	std::cout << xieite::string::toUppercase("hello, world!\n");
}
```
Output:
```
HELLO, WORLD!
```
