# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:Version \{\}
Defined in fragment [xieite:math.Version](../../../src/math/version.cpp)

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

    friend constexpr std::strong_ordering operator<=>(const Version&, const Version&) noexcept;

    friend bool operator==(const Version&, const Version&) = default;

    constexpr std::string string() const noexcept;
};
```
- major
- minor
- patch
- label
- [Version\(\)](./structures/version/1/operators/constructor.md)
- [operator<=>\(\)](./structures/version/1/operators/spaceship.md)
- [string\(\)](./structures/version/1/string.md)

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::Version(1, 43, 998, "alpha").string());
}
```
Output:
```
v1.43.998-alpha
```
