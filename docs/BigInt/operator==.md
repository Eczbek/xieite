# gcufl::BigInt::operator==
Declared in `<gcufl/BigInt.hpp>`
```cpp
[[nodiscard]]
constexpr bool operator==(gcufl::BigInt other) const noexcept;

template<std::integral N>
[[nodiscard]]
constexpr bool operator==(const N value) const noexcept;
```
## Example
```cpp
#include <gcufl/BigInt.hpp>
#include <iostream>

int main() {
	std::cout << std::boolalpha << (gcufl::BigInt(5) == gcufl::BigInt(6)) << '\n';
}
```
Output:
```
false
```
