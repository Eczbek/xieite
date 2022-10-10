# gcufl::BigInt::operator*=
Declared in `<gcufl/BigInt.hpp>`
```cpp
constexpr gcufl::BigInt operator*=(gcufl::BigInt other) const noexcept;

template<std::integral N>
constexpr gcufl::BigInt operator*=(const N value) const noexcept;
```
## Example
```cpp
#include <gcufl/BigInt.hpp>
#include <iostream>

int main() {
	gcufl::BigInt value(3);
	value *= gcufl::BigInt(-4);
	std::cout << value << '\n';
}
```
Output:
```
-12
```
