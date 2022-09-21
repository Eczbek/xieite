# gcufl::string::hash
Declared in `<gcufl/string/hash.hpp>`
```cpp
constexpr unsigned long long hash(std::string_view string) noexcept;
```
Hashes a string.
## Example
```cpp
#include <gcufl/string/hash.hpp>
#include <iostream>
int main() {
	switch (gcufl::string::hash("banana")) {
		case gcufl::string::hash("apple"):
			std::cout << "1\n";
			break;
		case gcufl::string::hash("banana"):
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
