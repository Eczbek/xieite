# [xieite](../../README.md)::[functions](../functions.md)::OperatorSuffix
Defined in header [<xieite/functions/OperatorSuffix.hpp>](../../include/xieite/functions/OperatorSuffix.hpp)

<br/>

An suffix operator thing

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<typename, auto>
struct OperatorSuffix;
```
### Template parameters
- An unnamed unconstrained type
- An unnamed `auto` value

<br/><br/>

```cpp
template<typename Result, typename LeftParameter, xieite::concepts::Functional<Result(LeftParameter)> auto callback>
struct OperatorSuffix<Result(LeftParameter), callback> {
	friend constexpr Result operator<(const LeftParameter&, const xieite::functions::OperatorSuffix<Result(LeftParameter), callback>&);
};
```
### Template parameters
- `Result` - The return type
- `LeftParameter` - The left parameter type
- `callback` - An `auto` value, satisfying `xieite::concepts::Functional` of `Result` of `LeftParameter`
### Public members
<pre><code>OperatorSuffix/
|- <a href="./OperatorSuffix/constructor.md">OperatorSuffix</a>
`- <a href="./OperatorSuffix/operatorMode.md">operator<</a>
</code></pre>

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/functions/OperatorSuffix.hpp>

int main() {
	xieite::functions::OperatorSuffix<int(int), [](int x) -> int {
		return x - 1;
	}> decrement;

	std::cout << (2 <decrement) << '\n';
}
```
Output:
```
1
```
