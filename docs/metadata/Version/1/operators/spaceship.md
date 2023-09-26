# [xieite](../../../../xieite.md)\:\:[metadata](../../../../metadata.md)\:\:[Version](../../../Version.md)\:\:operator\<=\>
Defined in header [<xieite/metadata/Version.hpp>](../../../../../include/xieite/metadata/Version.hpp)

&nbsp;

## Description
Compares two `xieite::metadata::Version`s, ingoring the label member object.

&nbsp;

## Synopses
#### 1)
```cpp
friend constexpr std::strong_ordering operator<=>(const xieite::metadata::Version& version1, const xieite::metadata::Version& version2) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/metadata/Version.hpp>

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
