# [xieite](../xieite.md)::[concepts](../concepts.md)::SameAs
Defined in header [<xieite/concepts/SameAs.hpp>](../../include/xieite/concepts/SameAs.hpp)

<br/>

Specifies that a type is the same as at least one of several other types

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any, typename... Others>
concept SameAs = (std::same_as<Any, Others> || ...);
```
### Template parameters
- `Any` - Any type
- `Others...` - Any types

<br/><br/>

## Example
```cpp
#include <iostream>
#include <string>
#include <xieite/concepts/SameAs.hpp>

template<xieite::concepts::SameAs<bool, char, int>>
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
