# xieite::concepts::OneOf
Defined in header `<xieite/concepts/OneOf.hpp>`

<br/>

Specifies that type `T` is one of `VV`.

<br/><br/>

## Declarations
```cpp
template<typename T, typename... VV>
concept OneOf = (std::same_as<T, VV> || ...);
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
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
