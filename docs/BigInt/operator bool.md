# gcufl::BigInt::operator bool
Declared in `<gcufl/BigInt.hpp>`
```cpp
[[nodiscard]]
constexpr operator bool() const noexcept;
```
Converts a `BigInt` to a boolean.
## Example
```cpp
#include <gcufl/BigInt.hpp>
#include <iostream>

int main() {
	std::cout << std::boolalpha
		<< static_cast<bool>(gcufl::BigInt(-17)) << '\n'
		<< static_cast<bool>(gcufl::BigInt(0)) << '\n';
}
```
Output:
```
true
false
```
