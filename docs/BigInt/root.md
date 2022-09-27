# gcufl::BigInt::root
Declared in `<gcufl/BigInt.hpp>`
```cpp
gcufl::BigInt root(const gcufl::BigInt& other) const;

template<std::integral N>
gcufl::BigInt root(const N value) const;
```
Calculates the root of a `BigInt`.
## Example
```cpp
#include <gcufl/BigInt.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::BigInt(27).root(3) << '\n';
}
```
Output:
```
3
```
