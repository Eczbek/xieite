# [`xieite`](../../README.md)`::`[`functions`](../../docs/functions.md)`::Infix`
Defined in header [`<xieite/functions/Infix.hpp>`](../../include/xieite/functions/Infix.hpp)

<br/>

An infix operator thing.

<br/><br/>

## Synopsis

<br/><br/>

### Member functions
- [`Infix`](../../docs/functions/Infix/constructor1.md)
- [`operator>`](../../docs/functions/Infix/operatorMore.md)
- [`operator<`](../../docs/functions/Infix/operatorLess.md)

<br/><br/>

### Member functions
- [`Infix`](../../docs/functions/Infix/constructor2.md)

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/functions/Infix.hpp>

int main() {
	xieite::functions::Infix<int(int, int)> multiply([](int x, int y) -> int {
		return x * y;
	});

	xieite::functions::Infix<int(int)> increment([](int x) -> int {
		return x + 1;
	});

	std::cout
		<< (2 <multiply> 2) << '\n'
		<< (1 <increment) << '\n'
		<< (increment> 7) << '\n';
}
```
Output:
```
4
2
8
```
