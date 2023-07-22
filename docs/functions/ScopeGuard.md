# [xieite](../xieite.md)::[functions](../functions.md)::ScopeGuard
Defined in header [<xieite/functions/ScopeGuard.hpp>](../../include/xieite/functions/ScopeGuard.hpp)

<br/>

Executes a callback when it goes out of scope

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::invocable<> Invocable>
struct ScopeGuard {
	ScopeGuard(const Invocable&);

	void release();
};
```
### Template parameters
- `Invocable` - A type satisfying `std::invocable`
### Public members
<pre><code>ScopeGuard/
|- <a href="./ScopeGuard/constructor.md">ScopeGuard</a>
`- <a href="./ScopeGuard/release.md">release</a>
</code></pre>

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/functions/ScopeGuard.hpp>

int main() {
	xieite::functions::ScopeGuard guard([] {
		std::cout << "foo\n";
	});

	std::cout << "bar\n";
}
```
Output:
```
bar
foo
```
