# [xieite](../xieite.md)\:\:[math](../math.md)\:\:absolute
Defined in header [<xieite/math/absolute.hpp>](../../include/xieite/math/absolute.hpp)

&nbsp;

## Description
Returns the unsigned absolute of a value.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr std::make_unsigned_t<Integer> absolute(Integer value) noexcept;
```
#### 2)
```cpp
template<std::floating_point FloatingPoint>
[[nodiscard]] constexpr FloatingPoint absolute(FloatingPoint value) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdint>
#include <iostream>
#include <xieite/math/absolute.hpp>

int main() {
    std::int16_t value = -32768;

    std::cout << xieite::math::absolute(value) << '\n';
}
```
Output:
```
32768
```
