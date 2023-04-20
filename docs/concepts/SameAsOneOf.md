# `xieite::concepts::SameAsOneOf`
Defined in header [`<xieite/concepts/SameAsOneOf.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/concepts/SameAsOneOf.hpp)

<br/>

Specifies that type `Any1` is the same as at least one of `Any2...`.

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any1, typename... Any2>
concept SameAsOneOf = (std::same_as<Any1, Any2> || ...);
```
### Template parameters
- `Any1` - Any type
- `Any2...` - Any types

<br/><br/>

## Example
```cpp
#include <iostream>
#include <string>
#include <xieite/concepts/SameAsOneOf.hpp>

template<xieite::concepts::SameAsOneOf<bool, char, int>>
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
