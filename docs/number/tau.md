# gcufl::number::tau_v
```cpp
template <typename N>
constexpr N tau_v = std::numbers::pi_v<N> * 2;

constexpr double tau = gcufl::number::tau_v<double>;
```
A mathematical constant.
## Example
```cpp
#include <iostream>
#include <gcufl/number.hpp>

int main() {
	std::cout << gcufl::number::tau << '\n';
}
```
Output:
```
6.28318
```
