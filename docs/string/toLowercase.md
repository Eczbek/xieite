# xieite::string::toLowercase
Declared in `<xieite/string/toLowercase.hpp>`

<br/>

Converts a string or character to lower case. Only handles characters `A` to `Z`.

<br/><br/>

## Declarations
```cpp
constexpr char toLowercase(char character) noexcept;
```
```cpp
constexpr std::string toLowercase(std::string string) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <xieite/string/toLowercase.hpp>

int main() {
	std::cout << xieite::string::toLowercase("HELLO, WORLD!\n");
}
```
Output:
```
hello, world!
```
