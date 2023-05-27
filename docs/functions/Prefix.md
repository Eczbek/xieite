# [xieite](../../README.md)::[functions](../functions.md)::Prefix
Defined in header [<xieite/functions/Prefix.hpp>](../../include/xieite/functions/Prefix.hpp)

<br/>

An prefix operator

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<typename>
struct Prefix;
```
### Template parameters
- An unnamed type

<br/><br/>

```cpp
template<typename Result, typename RightParameter>
struct Prefix<Result(RightParameter)> final {
	constexpr Prefix(const xieite::concepts::Functional<Result(RightParameter)> auto&);

	constexpr Result operator>(const RightParameter&) const;
};
```
### Template parameters
- `Result` - The return type
- `RightParameter` - The right parameter type
### Public members
<pre><code>Prefix/
|- <a href="./Prefix/constructor.md">Prefix</a>
`- <a href="./Prefix/operatorMode.md">operator></a>
</code></pre>

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
