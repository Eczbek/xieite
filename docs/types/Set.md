# [`xieite`](../../README.md)`::`[`types`](../../docs/types.md)`::Set`
Defined in header [`<xieite/types/Set.hpp>`](../../include/xieite/types/Set.hpp)

<br/>

Creates a `xieite::types::List` using only unique types of those provided.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
template<typename... Types>
using Set = decltype((xieite::types::List<>()->*...->*xieite::types::List<Types>()));
```
### Template parameters
- `Types...` - Any types
### Resulting type
- A `xieite::types::List` of one of each unique type of `Types...`

<br/><br/>

## Example
```cpp
#include <concepts>
#include <iostream>
#include <xieite/types/List.hpp>
#include <xieite/types/Set.hpp>

int main() {
	std::cout
		<< std::boolalpha
		<< std::same_as<
			xieite::types::List<int, char>,
			xieite::types::Set<int, int, char, int, char, char, int>
		> << '\n';
}
```
Output:
```
true
```
