# [xieite](../../README.md)::[functions](../functions.md)::Infix
Defined in header [<xieite/functions/Infix.hpp>](../../include/xieite/functions/Infix.hpp)

<br/>

An infix operator thing

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<typename>
struct Infix;
```
### Template parameters
- An unnamed type

<br/><br/>

```cpp
template<typename Result, typename Parameter>
struct Infix<Result(Parameter)> final {
	constexpr Infix(const xieite::concepts::Functional<Result(Parameter)> auto&);

	constexpr Result operator>(const Parameter&) const;

	friend constexpr Result operator<(const Parameter&, const xieite::functions::Infix<Result(Parameter)>&);
};
```
### Template parameters
- `Result` - The return type
- `Parameter` - The parameter type for both right and left possible sides
### Public members
<pre><code>Infix/
|- <a href="./Infix/constructor1.md">Infix</a>
|- <a href="./Infix/operatorMore.md">operator></a>
`- <a href="./Infix/operatorLess.md">operator<</a>
</code></pre>

<br/><br/>

```cpp
template<typename Result, typename LeftParameter, typename RightParameter>
struct Infix<Result(LeftParameter, RightParameter)> final {
	constexpr Infix(const xieite::concepts::Functional<Result(LeftParameter, RightParameter)> auto&);
};
```
### Template parameters
- `Result` - The return type
- `LeftParameter` - The left parameter type
- `RightParameter` - The right parameter type
### Public members
<pre><code>Infix/
`- <a href="./Infix/constructor2.md">Infix</a>
</code></pre>

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/functions/Infix.hpp>

int main() {
	xieite::functions::Infix<int(int, int)> multiply([](int x, int y) -> int {
		return x * y;
	});

	xieite::functions::Infix<int(int)> increment([](int x) -> int {
		return x + 1;
	});

	std::cout
		<< (2 <multiply> 2) << '\n'
		<< (1 <increment) << '\n'
		<< (increment> 7) << '\n';
}
```
Output:
```
4
2
8
```