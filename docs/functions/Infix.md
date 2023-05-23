# [`xieite`](../../README.md)`::`[`functions`](../../docs/functions.md)`::Infix`
Defined in header [`<xieite/functions/Infix.hpp>`](../../include/xieite/functions/Infix.hpp)

<br/>

An infix operator thing. Currently only works with both parameters.

<br/><br/>

## Synopsis

<br/>

### Member functions
- [`Infix`](../../docs/functions/Infix/constructor.md)

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/functions/Infix.hpp>

int main() {
	xieite::functions::Infix<int, int, int> x([](int a, int b) {
		return a * b;
	});

	std::cout << (2 |x| 2) << '\n';
}
```
Output:
```
4
```
