# gcufl::numbers::factorial
Declared in `<gcufl/numbers/factorial.hpp>`
```cpp
template<unsigned long long N>
constexpr unsigned long long factorial = N * gcufl::numbers::factorial<N - 1>;

template<>
constexpr unsigned long long factorial<0> = 1;
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
