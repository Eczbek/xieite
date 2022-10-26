# xieite::string::repeat
Declared in `<xieite/string/repeat.hpp>`
```cpp
[[nodiscard]]
std::string repeat(const std::string_view string, std::size_t count) noexcept;
```
Repeats a string.
## Example
```cpp
#include <xieite/string/repeat.hpp>
#include <iostream>

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
