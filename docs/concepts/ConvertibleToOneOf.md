# [xieite](../../README.md)::[concepts](../concepts.md)::ConvertibleToOneOf
Defined in header [<xieite/concepts/ConvertibleToOneOf.hpp>](../../include/xieite/concepts/ConvertibleToOneOf.hpp)

<br/>

Specifies that a type can be converted to at least one of several other types

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename From, typename... Tos>
concept ConvertibleToOneOf = (std::convertible_to<From, Tos> || ...);
```
### Template parameters
- `From` - Any type
- `Tos...` - Any types

<br/><br/>

## Example
```cpp
#include <iostream>
#include <string>
#include <xieite/concepts/ConvertibleToOneOf.hpp>

template<xieite::concepts::ConvertibleToOneOf<bool, char, int>>
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
