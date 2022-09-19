# gcufl::numbers::fibonacci
Declared in `<gcufl/numbers/fibonacci.hpp>`
```cpp
template<std::size_t N>
constexpr std::size_t fibonacci = gcufl::numbers::fibonacci<N - 1> + gcufl::numbers::fibonacci<N - 2>;

template<>
constexpr std::size_t fibonacci<1> = 1;

template<>
constexpr std::size_t fibonacci<0> = 0;
```
Recursive fibonacci template.
## Example
```cpp
#include <gcufl/numbers/fibonacci.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::numbers::fibonacci<11> << '\n';
}
```
Output:
```
89
```
