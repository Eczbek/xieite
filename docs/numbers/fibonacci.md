# xieite::numbers::fibonacci
Declared in `<xieite/numbers/fibonacci.hpp>`
```cpp
template<unsigned long long N>
constexpr unsigned long long fibonacci = xieite::numbers::fibonacci<N - 1> + xieite::numbers::fibonacci<N - 2>;

template<>
constexpr unsigned long long fibonacci<1> = 1;

template<>
constexpr unsigned long long fibonacci<0> = 0;
```
Recursive fibonacci template.
## Example
```cpp
#include <iostream>
#include <xieite/numbers/fibonacci.hpp>

int main() {
	std::cout << xieite::numbers::fibonacci<11> << '\n';
}
```
Output:
```
89
```
