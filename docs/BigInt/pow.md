# gcufl::BigInt::pow
```cpp
gcufl::BigInt pow(gcufl::BigInt other) const;

template <std::integral N>
gcufl::BigInt pow(const N value) const;
```
Calculates the BigInt to a power.
## Example
```cpp
#include <gcufl/BigInt.hpp>
#include <iostream>

int main() {
	gcufl::BigInt bigInt(2);
	std::cout << bigInt.pow(8) << '\n';
}
```
256
```
