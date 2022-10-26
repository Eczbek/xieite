# xieite::numbers::factorial
Declared in `<xieite/numbers/factorial.hpp>`
```cpp
template<unsigned long long N>
constexpr unsigned long long factorial = N * xieite::numbers::factorial<N - 1>;

template<>
constexpr unsigned long long factorial<0> = 1;
```
Recursive factorial template.
## Example
```cpp
#include <xieite/numbers/factorial.hpp>
#include <iostream>

int main() {
	std::cout << xieite::numbers::factorial<5> << '\n';
}
```
Output:
```
120
```
