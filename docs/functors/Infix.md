# [xieite](../xieite.md)::[functors](../functors.md)::Infix
Defined in header [<xieite/functors/Infix.hpp>](../../include/xieite/functors/Infix.hpp)

<br/>

An infix operator thing

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<typename Type, xieite::concepts::Functable<Type> auto>
struct Infix;
```
### Template parameters
- `Type` - The function type
- An unnamed `auto` value satisfying `xieite::concepts::Functable` of `Type`

<br/><br/>

```cpp
template<typename Result, typename Parameter, auto callback>
struct Infix<Result(Parameter), callback> {
	constexpr Result operator>(const Parameter&) const;

	friend constexpr Result operator<(const Parameter&, const xieite::functors::Infix<Result(Parameter), callback>&);
};
```
### Template parameters
- `Result` - The return type
- `Parameter` - The parameter type for both right and left possible sides
- `callback` - A value of any type value
### Public members
<pre><code>Infix/
|- <a href="./Infix1/operatorMore.md">operator></a>
`- <a href="./Infix1/operatorLess.md">operator<</a>
</code></pre>

<br/><br/>

```cpp
template<typename Result, typename LeftParameter, typename RightParameter, auto callback>
class Infix<Result(LeftParameter, RightParameter), callback> {
private:
	struct Intermediate {
		constexpr Result operator>(const RightParameter& rightArgument) const;
	};

public:
	friend constexpr xieite::functors::Infix<Result(LeftParameter, RightParameter), callback>::Intermediate operator<(const LeftParameter&, const xieite::functors::Infix<Result(LeftParameter, RightParameter), callback>&);
};
```
### Template parameters
- `Result` - The return type
- `LeftParameter` - The left parameter type
- `RightParameter` - The right parameter type
- `callback` - A value of any type value
### Public members
<pre><code>Infix/
|- Intermediate/
|  `- <a href="./Infix2/Intermediate/operatorMore.md">operator></a>
`- <a href="./Infix2/operatorLess.md">operator<</a>
</code></pre>

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/functors/Infix.hpp>

int main() {
	xieite::functors::Infix<int(int, int), [](int x, int y) {
		return x * y;
	}> multiply;

	xieite::functors::Infix<int(int), [](int x) {
		return x + 1;
	}> increment;

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
