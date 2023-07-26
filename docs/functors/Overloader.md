# [xieite](../xieite.md)::[functors](../functors.md)::Overloader
Defined in header [<xieite/functors/Overloader.hpp>](../../include/xieite/functors/Overloader.hpp)

<br/>

Extends multiple invocable types and overloads `operator()` for each. Ignores types which are not callable

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Derivable... Derivables>
struct Overloader
: xieite::functors::MakeFunctor<Derivables>... {
	constexpr Overloader(const Derivables&...);

	using xieite::functors::MakeFunctor<Derivables>::operator()...;
};
```
### Template parameters
- `Derivables...` - Any types satisfying `xieite::concepts::Derivable`, to be derived from
### Public members
<pre><code>Overloader/
|- <a href="./Overloader/constructor.md">Overloader</a>
`- <a href="./Overloader/operatorCall.md">operator()</a>
</code></pre>

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/functors/Overloader.hpp>

int main() {
	auto foo = [](int) -> void {
		std::cout << "foo\n";
	};
	auto bar = [](double) -> void {
		std::cout << "bar\n";
	};
	struct nope {};

	xieite::functors::Overloader overloader(foo, bar, nope());

	overloader(999);
	overloader(3.14159);
}
```
Output:
```
foo
bar
```
