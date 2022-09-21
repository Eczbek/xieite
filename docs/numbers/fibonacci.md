# gcufl::numbers::fibonacci
Declared in `<gcufl/numbers/fibonacci.hpp>`
```cpp
template<unsigned long long N>
constexpr unsigned long long fibonacci = gcufl::numbers::fibonacci<N - 1> + gcufl::numbers::fibonacci<N - 2>;

template<>
constexpr unsigned long long fibonacci<1> = 1;

template<>
constexpr unsigned long long fibonacci<0> = 0;
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
