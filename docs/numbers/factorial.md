# xieite::numbers::factorial
Declared in `<xieite/numbers/factorial.hpp>`
```cpp
template<std::integral auto N, template T = decltype(N)>
constexpr T factorial = N * xieite::numbers::factorial<N - 1, T>;

template<template T>
constexpr T factorial<static_cast<T>(0), T> = static_cast<T>(1);
```
Recursive factorial template.
## Example
```cpp
#include <iostream>
#include <xieite/numbers/factorial.hpp>

int main() {
	std::cout << xieite::numbers::factorial<5> << '\n';
}
```
Output:
```
120
```
