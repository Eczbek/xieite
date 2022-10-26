# xieite::string::hash
Declared in `<xieite/string/hash.hpp>`
```cpp
[[nodiscard]]
constexpr unsigned long long hash(const std::string_view string) noexcept;
```
Hashes a string.
## Example
```cpp
#include <iostream>
#include <xieite/string/hash.hpp>

int main() {
	switch (xieite::string::hash("banana")) {
		case xieite::string::hash("apple"):
			std::cout << "1\n";
			break;
		case xieite::string::hash("banana"):
			std::cout << "2\n";
			break;
		default:
			std::cout << "3\n";
	}
}
```
Output:
```
2
```
