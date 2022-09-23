# gcufl::BigInt::operator<
Declared in `<gcufl/BigInt.hpp>`
```cpp
bool operator<(gcufl::BigInt other) const noexcept;

template<std::integral N>
bool operator<(const N value) const noexcept;
```
## Example
```cpp
#include <gcufl/BigInt.hpp>
#include <iostream>

int main() {
	std::cout << std::boolalpha << (gcufl::BigInt(2) < gcufl::BigInt(7)) << '\n';
}
```
Output:
```
true
```
