# gcufl::BigInt::operator++
Declared in `<gcufl/BigInt.hpp>`
```cpp
constexpr gcufl::BigInt operator++() const noexcept;

constexpr gcufl::BigInt operator++(int) const noexcept;
```
## Example
```cpp
#include <gcufl/BigInt.hpp>
#include <iostream>

int main() {
	for (gcufl::BigInt i(0); i < 10; ++i)
		std::cout << i << '\n';
}
```
Output:
```
0
1
2
3
4
5
6
7
8
9
```
