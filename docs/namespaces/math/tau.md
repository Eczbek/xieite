# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:tau
Defined in header [<xieite/math/tau.hpp>](../../../include/xieite/math/tau.hpp)

&nbsp;

## Description
Defines a constant for tau.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
inline constexpr Number tau = xieite::math::pi<Number> * 2;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/tau.hpp"

int main() {
    std::println("{}", xieite::math::tau<double>);
}
```
Possible output:
```
6.283185307179586
```
