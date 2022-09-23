# gcufl::BigInt::operator!
Declared in `<gcufl/BigInt.hpp>`
```cpp
bool operator!() const noexcept;
```
## Example
```cpp
#include <gcufl/BigInt.hpp>
#include <iostream>

int main() {
	std::cout << std::boolalpha << !gcufl::BigInt(0) << '\n';
}
```
Output:
```
true
```
