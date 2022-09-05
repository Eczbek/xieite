# gcufl::numbers::tau
```cpp
template <typename N>
constexpr N tau_v = std::numbers::pi_v<N> * 2;

constexpr double tau = gcufl::numbers::tau_v<double>;
```
A mathematical constant.
## Example
```cpp
#include <iostream>
#include <gcufl/numbers.hpp>

int main() {
	std::cout << gcufl::numbers::tau << '\n';
}
```
Output:
```
6.28318
```
