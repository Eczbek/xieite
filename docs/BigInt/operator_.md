# gcufl::BigInt::operator/
Declared in `<gcufl/BigInt.hpp>`
```cpp
[[nodiscard]]
constexpr gcufl::BigInt operator/(gcufl::BigInt other) const;

template<std::integral N>
[[nodiscard]]
constexpr gcufl::BigInt operator/(const N value) const;
```
This file is named incorrectly due to naming limitations.
## Example
```cpp
#include <gcufl/BigInt.hpp>
#include <iostream>

int main() {
	std::cout << (gcufl::BigInt(10) / gcufl::BigInt(3)) << '\n';
}
```
Output:
```
3
```
