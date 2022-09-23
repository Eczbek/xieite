# gcufl::BigInt::operator!=
Declared in `<gcufl/BigInt.hpp>`
```cpp
bool operator!=(const gcufl::BigInt& other) const noexcept;

template<std::integral N>
bool operator!=(const N value) const noexcept;
```
## Example
```cpp
#include <gcufl/BigInt.hpp>
#include <iostream>

int main() {
	std::cout << (gcufl::BigInt(4) != gcufl::BigInt(4)) << '\n';
}
```
Output:
```
false
```
