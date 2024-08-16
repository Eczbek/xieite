# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Arithmetic\<\>
Defined in header [<xieite/concepts/arithmetic.hpp>](../../../include/xieite/concepts/arithmetic.hpp)

&nbsp;

## Description
Specifies that a type is an integer or floating point.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept Arithmetic = std::integral<Type> || std::floating_point<Type>;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/arithmetic.hpp"

template<xieite::concepts::Arithmetic T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::println("{}", add(2, 3));
    std::println("{}", add(5.1, 4.6));
}
```
Output:
```
5
9.7
```
