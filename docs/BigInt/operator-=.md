# gcufl::BigInt::operator-=
Declared in `<gcufl/BigInt.hpp>`
```cpp
gcufl::BigInt& operator-=(const gcufl::BigInt& other) noexcept;

template<std::integral N>
gcufl::BigInt& operator-=(const N value) noexcept;
```
## Example
```cpp
#include <gcufl/BigInt.hpp>
#include <iostream>

int main() {
	gcufl::BigInt value(10);
	value -= gcufl::BigInt(-3);
	std::cout << value << '\n';
}
```
Output:
```
13
```
