# gculf::num::tau_v
```cpp
template <typename N>
constexpr N tau_v = std::numbers::pi_v<N> * 2;

constexpr double tau = gcufl::num::tau_v<double>;
```
A mathematical constant.
## Example
```cpp
#include <iostream>
#include <gculf/num>

int main() {
	std::cout << gculf::num::tau << '\n';
}
```
Output:
```
6.28318
```
