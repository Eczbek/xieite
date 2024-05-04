# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:tau\<\>
Defined in header [<xieite/math/tau.hpp>](../../../include/xieite/math/tau.hpp)

&nbsp;

## Description
Defines a constant for tau.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
inline constexpr Arithmetic_ tau = xieite::math::pi<Arithmetic_> * 2;
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
