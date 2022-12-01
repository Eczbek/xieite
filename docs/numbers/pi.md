# xieite::numbers::pi
Declared in `<xieite/numbers/pi.hpp>`

<br/>

Defines integer varations of PI.

<br/><br/>

## Definitions
```cpp
template<std::floating_point N>
constexpr N pi = std::numbers::pi_v<N>;
```
```cpp
template<std::integral N>
constexpr N pi = 3;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/numbers/pi.hpp>

int main() {
	std::cout
		<< xieite::numbers::pi<double> << '\n'
		<< xieite::numbers::pi<int> << '\n';
}