# [`xieite`](../../README.md)`::`[`functions`](../../docs/functions.md)`::Overloader`
Defined in header [`<xieite/functions/Overloader.hpp>`](../../include/xieite/functions/Overloader.hpp)

<br/>

Extends multiple invocable types and overloads `operator()` for each. Ignores types which are not callable.

<br/><br/>

## Synopsis

<br/>

### Template parameters
- `Functions...` - Any types, satisfying `xieite::concepts::Derivable`, to be derived from
### Member functions
- [`Overloader`](../../docs/functions/Overloader/constructor.md)
- [`operator()`](../../docs/functions/Overloader/operatorCall.md)

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/functions/Overloader.hpp>

struct nope {};

int main() {
	auto foo = [](int) -> void {
		std::cout << "foo\n";
	};
	auto bar = [](double) -> void {
		std::cout << "bar\n";
	};
	xieite::functions::Overloader overloader(foo, bar, nope());

	overloader(999);
	overloader(3.14159);
}
```
Output:
```
foo
bar
```

<br/><br/>

## See also
- [`xieite::concepts::Derivable`](../../docs/concepts/Derivable.md)
