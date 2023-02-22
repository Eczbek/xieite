# xieite::string::truncate
Defined in header `<xieite/string/truncate.hpp>`

<br/>

Shortens the end of a string.

<br/><br/>

## Declaration
```cpp
[[nodiscard]]
constexpr std::string truncate(const std::string& string, const std::size_t length, const std::string& suffix = "") noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <xieite/string/truncate.hpp>

int main() {
	std::cout << xieite::string::truncate("Hello, world!", 8, "...") << '\n';
}
```
Output:
```
Hello...
```
