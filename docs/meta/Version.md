# [xieite](../xieite.md)\:\:[meta](../meta.md)\:\:Version
Defined in header [<xieite/meta/Version.hpp>](../../include/xieite/meta/Version.hpp)

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

    friend constexpr std::strong_ordering operator<=>(const xieite::meta::Version&, const xieite::meta::Version&);
    
    friend constexpr bool operator==(const xieite::meta::Version&, const xieite::meta::Version&);

    constexpr std::string string() const;
};
```
##### Member variables
- major
- minor
- patch
- label
##### Member functions
- [Version](./Version/1/operators/constructor.md)
- [operator<=>](./Version/1/operators/spaceship.md)
- [operator==](./Version/1/operators/equal.md)
- [string](./Version/1/string.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/meta/Version.hpp>

int main() {
    std::cout << xieite::meta::Version(1, 43, 998, "alpha").string() << '\n';
}
```
Output:
```
v1.43.998-alpha
```
