# [xieite](../xieite.md)\:\:[math](../math.md)\:\:pi
Defined in header [<xieite/math/pi.hpp>](../../include/xieite/math/pi.hpp)

&nbsp;

## Description
Defines integer values of Pi.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename>
inline constexpr double pi = std::numbers::pi;
```
#### 2)
```cpp
template<std::floating_point FloatingPoint>
inline constexpr FloatingPoint pi<FloatingPoint> = std::numbers::pi_v<FloatingPoint>;
```
#### 3)
```cpp
template<std::integral Integer>
inline constexpr Integer pi<Integer> = static_cast<Integer>(std::numbers::pi);
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/pi.hpp>

int main() {
    std::cout
        << xieite::math::pi<double> << '\n'
        << xieite::math::pi<int> << '\n';
}
```
Output:
```
3.14159
3
```
