# [xieite](../../../../../../xieite.md)\:\:[metadata](../../../../../../metadata.md)\:\:[Version](../../../../version.md)\:\:operator<=>
Defined in header [<xieite/metadata/version.hpp"](../../../../../../../include/xieite/metadata/version.hpp)

&nbsp;

## Description
Compares two `xieite::metadata::Version`s, ingoring the label member object.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::metadata::Version& version1, const xieite::metadata::Version& version2) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/metadata/version.hpp"

int main() {
    xieite::metadata::Version version1(1, 0, 0, "bbbbb");

    xieite::metadata::Version version2(1, 0, 1, "aaaaa");

    std::cout
        << std::boolalpha
        << (version1 < version2) << '\n';
}
```
Output:
```
true
```
