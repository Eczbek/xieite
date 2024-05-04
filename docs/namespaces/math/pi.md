# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:pi\<\>
Defined in header [<xieite/math/pi.hpp>](../../../include/xieite/math/pi.hpp)

&nbsp;

## Description
Defines integer values of Pi.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename>
inline constexpr double pi = std::numbers::pi;
```
#### 2)
```cpp
template<std::floating_point Fractional_>
inline constexpr Fractional_ pi<Fractional_> = std::numbers::pi_v<Fractional_>;
```
#### 3)
```cpp
template<std::integral Integral_>
inline constexpr Integral_ pi<Integral_> = static_cast<Integral_>(std::numbers::pi);
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/pi.hpp"

int main() {
    std::println("{}", xieite::math::pi<double>);
    std::println("{}", xieite::math::pi<int>);
}
```
Output:
```
3.14159
3
```
