# gcufl::BigInt::operator+
Declared in `<gcufl/BigInt.hpp>`
```cpp
gcufl::BigInt operator+() const noexcept;

gcufl::BigInt operator+(gcufl::BigInt other) const noexcept;

template<std::integral N>
gcufl::BigInt operator+(const N value) const noexcept;
```
## Example
```cpp
#include <gcufl/BigInt.hpp>
#include <iostream>

int main() {
	std::cout << (gcufl::BigInt(2) + gcufl::BigInt(-5)) << '\n';
}
```
Output:
```
-3
```
