# [xieite](../../README.md)::[functions](../functions.md)::Suffix
Defined in header [<xieite/functions/Suffix.hpp>](../../include/xieite/functions/Suffix.hpp)

<br/>

An suffix operator thing

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<typename, auto>
struct Suffix;
```
### Template parameters
- An unnamed unconstrained type
- An unnamed `auto` value

<br/><br/>

```cpp
template<typename Result, typename LeftParameter, xieite::concepts::Functional<Result(LeftParameter)> auto callback>
struct Suffix<Result(LeftParameter), callback> final {
	friend constexpr Result operator<(const LeftParameter&, const xieite::functions::Suffix<Result(LeftParameter), callback>&);
};
```
### Template parameters
- `Result` - The return type
- `LeftParameter` - The left parameter type
- `callback` - An `auto` value, satisfying `xieite::concepts::Functional` of `Result` of `LeftParameter`
### Public members
<pre><code>Suffix/
|- <a href="./Suffix/constructor.md">Suffix</a>
`- <a href="./Suffix/operatorMode.md">operator<</a>
</code></pre>

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/functions/Suffix.hpp>

int main() {
	xieite::functions::Suffix<int(int), [](int x) -> int {
		return x - 1;
	}> decrement;

	std::cout << (2 <decrement) << '\n';
}
```
Output:
```
1
```
