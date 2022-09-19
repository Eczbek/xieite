# gcufl::numbers::factorial
Declared in `<gcufl/numbers/factorial.hpp>`
```cpp
template<std::size_t N>
constexpr std::size_t factorial = N * gcufl::numbers::factorial<N - 1>;

template<>
constexpr std::size_t factorial<0> = 1;
```
Recursive factorial template.
## Example
```cpp
#include <gcufl/numbers/factorial.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::numbers::factorial<5> << '\n';
}
```
Output:
```
120
```
