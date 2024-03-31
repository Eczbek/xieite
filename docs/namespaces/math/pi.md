# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:pi
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
template<std::floating_point Fractional>
inline constexpr Fractional pi<Fractional> = std::numbers::pi_v<Fractional>;
```
#### 3)
```cpp
template<std::integral Integral>
inline constexpr Integral pi<Integral> = static_cast<Integral>(std::numbers::pi);
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
