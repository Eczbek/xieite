# xieite::string::repeat
Declared in `<xieite/string/repeat.hpp>`

<br/>

Repeats a string.

<br/><br/>

## Declaration
```cpp
[[nodiscard]]
constexpr std::string repeat(const std::string_view string, std::size_t count) noexcept;
```

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
