# [xieite](../../xieite.md)\:\:[meta](../../meta.md)\:\:[Version](../Version.md)\:\:operator\<=\>
Defined in header [<xieite/meta/Version.hpp>](../../../include/xieite/meta/Version.hpp)

&nbsp;

## Description
Compares two `xieite::meta::Version`s, ingoring the label member object.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]]
constexpr std::strong_ordering operator<=>(const xieite::meta::Version& version) const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/meta/Version.hpp>

int main() {
    xieite::meta::Version version1(1, 0, 0, "bbbbb");

    xieite::meta::Version version2(1, 0, 1, "aaaaa");

    std::cout
        << std::boolalpha
        << (version1 < version2) << '\n';
}
```
Output:
```
true
```
