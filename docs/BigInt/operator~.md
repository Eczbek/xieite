# gcufl::BigInt::operator~
Declared in `<gcufl/BigInt.hpp>`
```cpp
gcufl::BigInt operator~() const noexcept;
```
## Example
```cpp
#include <gcufl/BigInt.hpp>
#include <iostream>

int main() {
	std::cout << ~gcufl::BigInt(1) << '\n';
}
```
Output:
```
-2
```
