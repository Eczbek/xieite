# [xieite](../xieite.md)::[functors](../functors.md)::Postfix
Defined in header [<xieite/functors/Postfix.hpp>](../../include/xieite/functors/Postfix.hpp)

<br/>

A postfix operator thing

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<typename Type, xieite::concepts::Functable<Type> auto>
struct Postfix;
```
### Template parameters
- `Type` - The function type
- An unnamed `auto` value satisfying `xieite::concepts::Functable` of `Type`

<br/><br/>

```cpp
template<typename Result, typename LeftParameter, auto callback>
struct Postfix<Result(LeftParameter), callback> {
	friend constexpr Result operator<(const LeftParameter&, const xieite::functors::Postfix<Result(LeftParameter), callback>&);
};
```
### Template parameters
- `Result` - The return type
- `LeftParameter` - The left parameter type
- `callback` - A value of any type value
### Public members
<pre><code>Postfix/
`- <a href="./Postfix/operatorMode.md">operator<</a>
</code></pre>

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/functors/Postfix.hpp>

int main() {
	xieite::functors::Postfix<int(int), [](int x) {
		return x - 1;
	}> decrement;

	std::cout << (2 <decrement) << '\n';
}
```
Output:
```
1
```
