# gcufl::BigInt::abs
Declared in `<gcufl/BigInt.hpp>`
```cpp
[[nodiscard]]
constexpr gcufl::BigInt abs() const noexcept;
```
Gets the absolute value of a `BigInt`.
## Example
```cpp
#include <gcufl/BigInt.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::BigInt(-43).abs() << '\n';
}
```
Output:
```
43
```
