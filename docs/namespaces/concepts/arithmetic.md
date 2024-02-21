# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Arithmetic
Defined in header [<xieite/concepts/arithmetic.hpp"](../../../include/xieite/concepts/arithmetic.hpp)

&nbsp;

## Description
Specifies that a type is integral, floating point, or boolean.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
concept Arithmetic = std::is_arithmetic_v<Type>;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/arithmetic.hpp"

template<xieite::concepts::Arithmetic Number>
Number add(Number a, Number b) {
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
