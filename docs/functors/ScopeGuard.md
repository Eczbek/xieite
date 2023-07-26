# [xieite](../xieite.md)::[functors](../functors.md)::ScopeGuard
Defined in header [<xieite/functors/ScopeGuard.hpp>](../../include/xieite/functors/ScopeGuard.hpp)

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
#include <xieite/functors/ScopeGuard.hpp>

int main() {
	xieite::functors::ScopeGuard guard([] {
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
