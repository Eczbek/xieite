# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:isNegative\<\>\(\)
Defined in header [<xieite/math/is_negative.hpp>](../../../include/xieite/math/is_negative.hpp)

&nbsp;

## Description
Checks that a value is negative.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr bool isNegative(Arithmetic value) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/is_negative.hpp"

int main() {
    std::println("{}", xieite::math::isNegative(4));
    std::println("{}", xieite::math::isNegative(-23));
}
```
Output:
```
false
true
```
