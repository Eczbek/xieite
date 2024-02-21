# [xieite](../../xieite.md)\:\:[metadata](../../metadata.md)\:\:Version
Defined in header [<xieite/metadata/version.hpp"](../../../include/xieite/metadata/version.hpp)

&nbsp;

## Description
A class to store and compare versions.

&nbsp;

## Synopses
#### 1)
```cpp
struct Version {
    std::size_t major;
    std::size_t minor;
    std::size_t patch;
    std::string label;

    constexpr Version(std::size_t = 0, std::size_t = 0, std::size_t = 0, std::string_view = "");

    friend constexpr std::strong_ordering operator<=>(const xieite::metadata::Version&, const xieite::metadata::Version&);

    friend constexpr bool operator==(const xieite::metadata::Version&, const xieite::metadata::Version&);

    constexpr std::string string() const;
};
```
##### Member variables
- major
- minor
- patch
- label
##### Member functions
- [Version](./structures/version/1/operators/constructor.md)
- [operator<=>](./structures/version/1/operators/spaceship.md)
- [operator==](./structures/version/1/operators/equal.md)
- [string](./structures/version/1/string.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/metadata/version.hpp"

int main() {
    std::cout << xieite::metadata::Version(1, 43, 998, "alpha").string() << '\n';
}
```
Output:
```
v1.43.998-alpha
```
