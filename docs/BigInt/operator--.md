# gcufl::BigInt::operator--
Declared in `<gcufl/BigInt.hpp>`
```cpp
gcufl::BigInt& operator--() noexcept;

gcufl::BigInt operator--(int) noexcept;
```
Decrements the value of a `BigInt` by 1.
## Example
```cpp
#include <gcufl/BigInt.hpp>
#include <iostream>

int main() {
	for (gcufl::BigInt i(10); i > 0; --i)
		std::cout << i << '\n';
}
```
Output:
```
10
9
8
7
6
5
4
3
2
1
```
