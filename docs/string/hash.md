# xieite::string::hash
Defined in header `<xieite/string/hash.hpp>`

<br/>

"Hashes" a string for use in a `switch`. Collisions may occur.

<br/><br/>

## Declaration
```cpp
[[nodiscard]]
constexpr unsigned long long hash(const std::string_view string) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
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
