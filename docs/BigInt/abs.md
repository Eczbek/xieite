# gcufl::BigInt::abs
```cpp
gcufl::BigInt abs() const noexcept;
```
Gets the absolute value of the BigInt.
## Example
```cpp
#include <iostream>
#include <gcufl/BigInt.hpp>

int main() {
	gcufl::BigInt bigInt(-12);
	std::cout << bigInt.abs() << '\n';
}
```
Output:
```
12
```
