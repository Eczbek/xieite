# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:Arithmetic
Defined in header [<xieite/concepts/Arithmetic.hpp>](../../include/xieite/concepts/Arithmetic.hpp)

&nbsp;

## Description
Specifies that a type is an integer or a floating point.

&nbsp;

## Synopsis
```cpp
template<typename Type>
concept Arithmetic = std::is_arithmetic_v<Type>;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/concepts/Arithmetic.hpp>

template<xieite::concepts::Arithmetic N>
N add(N a, N b) {
    return a + b;
}

int main() {
    std::cout
        << add(2, 3) << '\n'
        << add(5.1, 4.6) << '\n';
}
```
Output:
```
5
9.7
```
