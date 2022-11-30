# xieite::math::PiGenerator
Declared in `<xieite/math/PiGenerator.hpp>`

<br/>

Calculates digits of PI.

<br/><br/>

## Constructor
```cpp
constexpr PiGenerator() noexcept;
```

## Methods
```cpp
template<std::integral N = int>
constexpr N next() noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/PiGenerator.hpp>

int main() {
	xieite::math::PiGenerator pi;
	
	for (int i = 0; i < 50; ++i)
		std::cout << pi.next();
	std::cout << '\n';
}
```
Output:
```
31415926535897932384626433832795028841971693993751
```
