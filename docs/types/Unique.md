# [xieite](../../README.md)::[types](../types.md)::Unique
Defined in header [<xieite/types/Unique.hpp>](../../include/xieite/types/Unique.hpp)

<br/>

Creates a `xieite::types::List` using only unique types of those provided

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename... Types>
using Unique = decltype((xieite::types::List<>()->*...->*xieite::types::List<Types>()));
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
#include <xieite/types/Unique.hpp>

int main() {
	std::cout
		<< std::boolalpha
		<< std::same_as<
			xieite::types::List<int, char>,
			xieite::types::Unique<int, int, char, int, char, char, int>
		>
		<< '\n';
}
```
Output:
```
true
```
