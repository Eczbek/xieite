# [xieite](../../README.md)::[functions](../functions.md)::Suffix
Defined in header [<xieite/functions/Suffix.hpp>](../../include/xieite/functions/Suffix.hpp)

<br/>

An suffix operator

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<typename>
struct Suffix;
```
### Template parameters
- An unnamed type

<br/><br/>

```cpp
template<typename Result, typename LeftParameter>
struct Suffix<Result(LeftParameter)> final {
	constexpr Suffix(const xieite::concepts::Functional<Result(LeftParameter)> auto&);

	friend constexpr Result operator<(const LeftParameter&, const xieite::functions::Suffix<Result(LeftParameter)>&);
};
```
### Template parameters
- `Result` - The return type
- `LeftParameter` - The left parameter type
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
	xieite::functions::Suffix<int(int)> decrement([](int x) -> int {
		return x - 1;
	});

	std::cout << (2 <decrement) << '\n';
}
```
Output:
```
1
```
