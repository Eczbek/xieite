# gcufl::concepts::Arithmetic
Declared in `<gcufl/concepts/Arithmetic.hpp>`
```cpp
template <typename T>
concept Arithmetic = std::is_arithmetic_v<T>;
```
Specifies that a type `T` is arithmetic.
## Example
```cpp
#include <gcufl/concepts/Arithmetic.hpp>
#include <iostream>

template <gcufl::concepts::Arithmetic N>
N add(const N a, const N b) {
	return a + b;
}

int main() {
	std::cout << add(2, 3) << '\n'
		<< add(5.1, 4.6) << '\n';
}
```
Output:
```
5
9.7
```
