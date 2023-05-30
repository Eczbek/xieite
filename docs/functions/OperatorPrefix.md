# [xieite](../../README.md)::[functions](../functions.md)::OperatorPrefix
Defined in header [<xieite/functions/OperatorPrefix.hpp>](../../include/xieite/functions/OperatorPrefix.hpp)

<br/>

An prefix operator thing

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<typename, auto>
struct OperatorPrefix;
```
### Template parameters
- An unnamed unconstrained type
- An unnamed `auto` value

<br/><br/>

```cpp
template<typename Result, typename RightParameter, xieite::concepts::Functional<Result(RightParameter)> auto callback>
struct OperatorPrefix<Result(RightParameter), callback> {
	constexpr Result operator>(const RightParameter&) const;
};
```
### Template parameters
- `Result` - The return type
- `RightParameter` - The right parameter type
- `callback` - An `auto` value, satisfaying `xieite::concepts::Functional` of `Result` of `RightParameter`
### Public members
<pre><code>OperatorPrefix/
|- <a href="./OperatorPrefix/constructor.md">OperatorPrefix</a>
`- <a href="./OperatorPrefix/operatorMode.md">operator></a>
</code></pre>

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/functions/OperatorPrefix.hpp>

int main() {
	xieite::functions::OperatorPrefix<int(int), [](int x) -> int {
		return x + 1;
	}> increment;

	std::cout << (increment> 2) << '\n';
}
```
Output:
```
3
```
