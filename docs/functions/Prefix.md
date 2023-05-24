# [`xieite`](../../README.md)`::`[`functions`](../../docs/functions.md)`::Prefix`
Defined in header [`<xieite/functions/Prefix.hpp>`](../../include/xieite/functions/Prefix.hpp)

<br/>

An prefix operator.

<br/><br/>

## Synopses

<br/><br/>

### Template parameters
- An unnamed type

<br/><br/>

### Template parameters
- `Result` - The return type
- `RightParameter` - The right parameter type
### Member functions
- [`Prefix`](../../docs/functions/Prefix/constructor.md)
- [`operator>`](../../docs/functions/Prefix/operatorMore.md)

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/functions/Prefix.hpp>

int main() {
	xieite::functions::Prefix<int(int)> increment([](int x) -> int {
		return x + 1;
	});

	std::cout << (increment> 2) << '\n';
}
```
Output:
```
3
```
