# operator<<
Declared in `<gcufl/BigInt.hpp>`
```cpp
friend std::ostream& operator<<(std::ostream& stream, const gcufl::BigInt& self);
```
Prints a `BigInt` into a `std::ostream`.
## Example
```cpp
#include <gcufl/BigInt.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::BigInt(-10) << '\n';
}
```
Output:
```
-10
```
