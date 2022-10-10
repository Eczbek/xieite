# gcufl::BigInt::operator/=
Declared in `<gcufl/BigInt.hpp>`
```cpp
constexpr gcufl::BigInt operator/=(gcufl::BigInt other) const;

template<std::integral N>
constexpr gcufl::BigInt operator/=(const N value) const;
```
This file is named incorrectly due to naming limitations.
## Example
```cpp
#include <gcufl/BigInt.hpp>
#include <iostream>

int main() {
	gcufl::BigInt value(10);
	value /= 3;
	std::cout << value << '\n';
}
```
Output:
```
3
```
