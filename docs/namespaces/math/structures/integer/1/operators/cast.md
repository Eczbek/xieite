# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits, sign>](../../../../integer.md)\:\:operator typename\(\)
Defined in header [<xieite/math/integer.hpp>](../../../../../../../include/xieite/math/integer.hpp)

&nbsp;

## Description
Casts a `xieite::math::Integer<bits, sign>` to another integer type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr operator Integer() const noexcept;
```
#### 2)
```cpp
template<std::size_t otherBits, bool otherSign>
[[nodiscard]] constexpr operator xieite::math::Integer<otherBits, otherSign>() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/integer.hpp"

int main() {
    std::println("{}", static_cast<xieite::math::Integer<3, false>>(xieite::math::Integer<4, false>(9)).data());
}
```
Output:
```
1
```
