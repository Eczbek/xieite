# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:Version \{\}
Defined in header [<xieite/math/version.hpp>](../../../include/xieite/math/version.hpp)

&nbsp;

## Description
A structure to store and compare versions.

&nbsp;

## Synopsis
#### 1)
```cpp
struct Version {
    std::size_t major;
    std::size_t minor;
    std::size_t patch;
    std::string label;

    constexpr Version(std::size_t = 0, std::size_t = 0, std::size_t = 0, std::string_view = "") noexcept;

    friend constexpr std::strong_ordering operator<=>(const xieite::math::Version&, const xieite::math::Version&) noexcept;

    friend constexpr bool operator==(const xieite::math::Version&, const xieite::math::Version&) noexcept;

    constexpr std::string string() const noexcept;
};
```
##### Members
- major
- minor
- patch
- label
- [Version\(\)](./structures/version/1/operators/constructor.md)
- [operator<=>\(\)](./structures/version/1/operators/spaceship.md)
- [operator==\(\)](./structures/version/1/operators/equal.md)
- [string\(\)](./structures/version/1/string.md)

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/version.hpp"

int main() {
    std::println("{}", xieite::math::Version(1, 43, 998, "alpha").string());
}
```
Output:
```
v1.43.998-alpha
```
