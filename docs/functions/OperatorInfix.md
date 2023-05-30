# [xieite](../../README.md)::[functions](../functions.md)::OperatorInfix
Defined in header [<xieite/functions/OperatorInfix.hpp>](../../include/xieite/functions/OperatorInfix.hpp)

<br/>

An infix operator thing

<br/><br/>

## Synopses

<br/><br/>

```cpp
template<typename, auto>
struct OperatorInfix;
```
### Template parameters
- An unnamed unconstrained type
- An unnamed `auto` value

<br/><br/>

```cpp
template<typename Result, typename Parameter, xieite::concepts::Functional<Result(Parameter)> auto callback>
struct OperatorInfix<Result(Parameter), callback> {
	constexpr Result operator>(const Parameter&) const;

	friend constexpr Result operator<(const Parameter&, const xieite::functions::OperatorInfix<Result(Parameter), callback>&);
};
```
### Template parameters
- `Result` - The return type
- `Parameter` - The parameter type for both right and left possible sides
- `callback` - An `auto` value, satisfying `xieite::concepts::Functional` of `Result` of `Parameter`
### Public members
<pre><code>OperatorInfix/
|- <a href="./OperatorInfix1/operatorMore.md">operator></a>
`- <a href="./OperatorInfix1/operatorLess.md">operator<</a>
</code></pre>

<br/><br/>

```cpp
template<typename Result, typename LeftParameter, typename RightParameter, xieite::concepts::Functional<Result(LeftParameter, RightParameter)> auto callback>
class OperatorInfix<Result(LeftParameter, RightParameter), callback> {
private:
	struct Intermediate {
		constexpr Result operator>(const RightParameter& rightArgument) const;
	};

public:
	friend constexpr xieite::functions::OperatorInfix<Result(LeftParameter, RightParameter), callback>::Intermediate operator<(const LeftParameter&, const xieite::functions::OperatorInfix<Result(LeftParameter, RightParameter), callback>&);
};
```
### Template parameters
- `Result` - The return type
- `LeftParameter` - The left parameter type
- `RightParameter` - The right parameter type
- `callback` - An `auto` value, satisfying `xieite::concepts::Functional` of `Result` of `LeftParameter` and `RightParameter`
### Public members
<pre><code>OperatorInfix/
|- Intermediate/
|  `- <a href="./OperatorInfix2/Intermediate/operatorMore.md">operator></a>
`- <a href="./OperatorInfix2/operatorLess.md">operator<</a>
</code></pre>

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/functions/OperatorInfix.hpp>

int main() {
	xieite::functions::OperatorInfix<int(int, int), [](int x, int y) -> int {
		return x * y;
	}> multiply;

	xieite::functions::OperatorInfix<int(int), [](int x) -> int {
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
