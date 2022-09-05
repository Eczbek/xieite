# gcufl::BigInt::operator<<
```cpp
friend std::ostream& operator<<(std::ostream& stream, const gcufl::BigInt& self)
```
Prints a BigInt to `std::cout`.
## Example
```cpp
#include <gcufl/BigInt.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::BigInt(-903557777) << '\n';
}
```
Output:
```
-903557777
```
