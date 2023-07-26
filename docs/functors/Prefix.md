# [xieite](../xieite.md)::[functors](../functors.md)::Prefix
Defined in header [<xieite/functors/Prefix.hpp>](../../include/xieite/functors/Prefix.hpp)

<br/>

An prefix operator thing

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<typename Type, xieite::concepts::Functable<Type> auto>
struct Prefix;
```
### Template parameters
- `Type` - The function type
- An unnamed `auto` value satisfying `xieite::concepts::Functable` of `Type`

<br/><br/>

```cpp
template<typename Result, typename RightParameter, auto callback>
struct Prefix<Result(RightParameter), callback> {
	constexpr Result operator>(const RightParameter&) const;
};
```
### Template parameters
- `Result` - The return type
- `RightParameter` - The right parameter type
- `callback` - A value of any type value
### Public members
<pre><code>Prefix/
`- <a href="./Prefix/operatorMode.md">operator></a>
</code></pre>

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/functors/Prefix.hpp>

int main() {
	xieite::functors::Prefix<int(int), [](int x) -> int {
		return x + 1;
	}> increment;

	std::cout << (increment> 2) << '\n';
}
```
Output:
```
3
```
