# xieite::concepts::Arithmetic
Declared in `<xieite/concepts/Arithmetic.hpp>`

<br/><br/>

## Declaration
```cpp
template<typename T>
concept Arithmetic = std::is_arithmetic_v<T>;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <xieite/concepts/Arithmetic.hpp>

template<xieite::concepts::Arithmetic N>
N add(N a, N b) {
	return a + b;
}

int main() {
	std::cout
		<< add(2, 3) << '\n'
		<< add(5.1, 4.6) << '\n';
}
```
Output:
```
5
9.7
```
