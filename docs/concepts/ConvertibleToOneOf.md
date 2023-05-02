# [`xieite`](../../README.md)`::`[`concepts`](../../docs/concepts.md)`::ConvertibleToOneOf`
Defined in header [`<xieite/concepts/ConvertibleToOneOf.hpp>`](../../include/xieite/concepts/ConvertibleToOneOf.hpp)

<br/>

Specifies that type `Any1` can be converted to at least one of `Any2...`.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
template<typename Any1, typename... Any2>
concept ConvertibleToOneOf = (std::convertible_to<Any1, Any2> || ...);
```
### Template parameters
- `Any1` - Any type
- `Any2...` - Any types

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
