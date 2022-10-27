# xieite::numbers::fibonacci
Declared in `<xieite/numbers/fibonacci.hpp>`
```cpp
template<std::integral auto N, typename T = decltype(N)>
constexpr T fibonacci = xieite::numbers::fibonacci<N - 1, T> + xieite::numbers::fibonacci<N - 2, T>;

template<typename T>
constexpr T fibonacci<static_cast<T>(1), T> = static_cast<T>(1);

template<typename T>
constexpr T fibonacci<static_cast<T>(0), T> = static_cast<T>(0);
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
