# xieite::concepts::OneOf
Defined in header `<xieite/concepts/OneOf.hpp>`

<br/>

Specifies that type `Any1` is one of `Any2`.

<br/><br/>

## Declarations
```cpp
template<typename Any1, typename... Any2>
concept OneOf = (std::same_as<Any1, Any2> || ...);
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/concepts/OneOf.hpp>

template<xieite::concepts::OneOf<bool, char, int> T>
void test() {
	std::cout << "foo\n";
}

template<typename T>
void test() {
	std::cout << "bar\n";
}

int main() {
	test<char>();
	test<long long>();
}
```
Output:
```
foo
bar
```
