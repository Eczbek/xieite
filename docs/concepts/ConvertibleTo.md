# [xieite](../../README.md)::[concepts](../concepts.md)::ConvertibleTo
Defined in header [<xieite/concepts/ConvertibleTo.hpp>](../../include/xieite/concepts/ConvertibleTo.hpp)

<br/>

Specifies that a type can be converted to at least one of several other types

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename From, typename... Tos>
concept ConvertibleTo = (std::convertible_to<From, Tos> || ...);
```
### Template parameters
- `From` - Any type
- `Tos...` - Any types

<br/><br/>

## Example
```cpp
#include <iostream>
#include <string>
#include <xieite/concepts/ConvertibleTo.hpp>

template<xieite::concepts::ConvertibleTo<bool, char, int>>
void test() {
	std::cout << "foo\n";
}

template<typename>
void test() {
	std::cout << "bar\n";
}

int main() {
	test<char>();
	test<std::string>();
}
```
Output:
```
foo
bar
```
