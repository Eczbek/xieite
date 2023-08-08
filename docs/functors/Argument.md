# [xieite](../xieite.md)\:\:[functors](../functors.md)\:\:Argument
Defined in header [<xieite/functors/Argument.hpp>](../../include/xieite/functors/Argument.hpp)

&nbsp;

## Description
Extracts a type by index from `xieite::functors::Arguments`.

&nbsp;

## Synopsis
```cpp
template<typename Functor, std::size_t index>
using Argument = std::tuple_element_t<index, xieite::functors::Arguments<Functor>>;
```

&nbsp;

## Example
```cpp
#include <concepts>
#include <iostream>
#include <xieite/functors/Argument.hpp>

int main() {
	auto lambda = [](int x, double y, char z) {
		return x > y && z;
	};

	std::cout << std::boolalpha << std::same_as<double, xieite::functors::Argument<decltype(lambda), 1>> << '\n';
}
```
Output:
```
true
```
