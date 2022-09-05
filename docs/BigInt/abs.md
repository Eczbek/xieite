# gcufl::BigInt::abs
```cpp
gcufl::BigInt abs() const noexcept;
```
Gets the absolute value of the BigInt.
## Example
```cpp
#include <gcufl/BigInt.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::BigInt(-12).abs() << '\n';
}
```
Output:
```
12
```
