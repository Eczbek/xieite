# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits_, sign_>](../../../integer.md)\:\:data\(\)
Defined in header [<xieite/math/integer.hpp>](../../../../../../include/xieite/math/integer.hpp)

&nbsp;

## Description
Returns the underlying integer value.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr xieite::math::Integer<bits_, sign_>::Limb data() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/integer.hpp"

int main() {
    xieite::math::Integer<3, false> integer = 14;

    std::println("{}", integer.data());
}
```
Output:
```
6
```
