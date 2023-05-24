# [`xieite`](../../README.md)`::`[`functions`](../../docs/functions.md)`::Suffix`
Defined in header [`<xieite/functions/Suffix.hpp>`](../../include/xieite/functions/Suffix.hpp)

<br/>

An suffix operator.

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
### Member functions
- [`Suffix`](../../docs/functions/Suffix/constructor.md)
- [`operator<`](../../docs/functions/Suffix/operatorLess.md)

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
