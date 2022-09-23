# gcufl::BigInt::pow
Declared in `<gcufl/BigInt.hpp>`
```cpp
gcufl::BigInt pow(gcufl::BigInt other) const;

template<std::integral N>
gcufl::BigInt pow(const N value) const
```
## Example
```cpp
#include <gcufl/BigInt.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::BigInt(2).pow(16) << '\n';
}
```
Output:
```
65536
```
