# [xieite](../../../../../../xieite.md)\:\:[math](../../../../../../math.md)\:\:[Version](../../../../version.md)\:\:operator\<=\>\(\)
Defined in header [<xieite/math/version.hpp>](../../../../../../../include/xieite/math/version.hpp)

&nbsp;

## Description
Compares two `xieite::math::Version`s, ingoring the label member object.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::math::Version& version1, const xieite::math::Version& version2) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/version.hpp"

int main() {
    auto version1 = xieite::math::Version(1, 0, 0, "bbbbb");

    auto version2 = xieite::math::Version(1, 0, 1, "aaaaa");

    std::println("{}", version1 < version2);
}
```
Output:
```
true
```
