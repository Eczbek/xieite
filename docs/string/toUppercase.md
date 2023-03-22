# xieite::string::toUppercase
Defined in header `<xieite/string/toUppercase.hpp>`

<br/>

Converts a string or character to uppercase. Only handles characters `a` to `z`.

<br/><br/>

## Declarations
```cpp
constexpr char toUppercase(char character) noexcept;
```
```cpp
constexpr std::string toUppercase(std::string string) noexcept;
```

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
