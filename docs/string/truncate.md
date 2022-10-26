# xieite::string::truncate
Declared in `<xieite/string/truncate.hpp>`
```cpp
[[nodiscard]]
std::string truncate(const std::string& string, const std::size_t length, const std::string& suffix = "") noexcept;
```
Replaces the end of a string.
## Example
```cpp
#include <xieite/string/truncate.hpp>
#include <iostream>

int main() {
	std::cout << xieite::string::truncate("Hello, world!", 8, "...") << '\n';
}
```
Output:
```
Hello...
```
