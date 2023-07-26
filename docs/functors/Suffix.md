# [xieite](../xieite.md)::[functors](../functors.md)::Suffix
Defined in header [<xieite/functors/Suffix.hpp>](../../include/xieite/functors/Suffix.hpp)

<br/>

An suffix operator thing

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<typename Type, xieite::concepts::Functable<Type> auto>
struct Suffix;
```
### Template parameters
- `Type` - The function type
- An unnamed `auto` value satisfying `xieite::concepts::Functable` of `Type`

<br/><br/>

```cpp
template<typename Result, typename LeftParameter, auto callback>
struct Suffix<Result(LeftParameter), callback> {
	friend constexpr Result operator<(const LeftParameter&, const xieite::functors::Suffix<Result(LeftParameter), callback>&);
};
```
### Template parameters
- `Result` - The return type
- `LeftParameter` - The left parameter type
- `callback` - A value of any type value
### Public members
<pre><code>Suffix/
`- <a href="./Suffix/operatorMode.md">operator<</a>
</code></pre>

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/functors/Suffix.hpp>

int main() {
	xieite::functors::Suffix<int(int), [](int x) -> int {
		return x - 1;
	}> decrement;

	std::cout << (2 <decrement) << '\n';
}
```
Output:
```
1
```
