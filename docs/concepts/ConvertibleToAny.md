# [xieite](../xieite.md)::[concepts](../concepts.md)::ConvertibleToAny
Defined in header [<xieite/concepts/ConvertibleToAny.hpp>](../../include/xieite/concepts/ConvertibleToAny.hpp)

<br/>

Specifies that a type can be converted to at least one of several other types

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename From, typename... Tos>
concept ConvertibleToAny = (std::convertible_to<From, Tos> || ...);
```
### Template parameters
- `From` - Any type
- `Tos...` - Any types

<br/><br/>

## Example
```cpp
#include <iostream>
#include <string>
#include <xieite/concepts/ConvertibleToAny.hpp>

template<xieite::concepts::ConvertibleToAny<bool, char, int>>
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
