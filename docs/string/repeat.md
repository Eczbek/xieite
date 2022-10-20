# gcufl::string::repeat
Declared in `<gcufl/string/repeat.hpp>`
```cpp
[[nodiscard]]
std::string repeat(const std::string_view string, std::size_t count) noexcept;
```
Repeats a string.
## Example
```cpp
#include <gcufl/string/repeat.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::string::repeat("Hello, world!\n", 3);
}
```
Output:
```
Hello, world!
Hello, world!
Hello, world!
```
