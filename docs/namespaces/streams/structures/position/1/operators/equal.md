# [xieite](../../../../../../xieite.md)\:\:[streams](../../../../../../streams.md)\:\:[Position](../../../../position.md)\:\:operator==\(\)
Defined in header [<xieite/streams/position.hpp>](../../../../../../../include/xieite/streams/position.hpp)

&nbsp;

## Description
Compares two `xieite::streams::Position`s.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr bool operator==(xieite::streams::Position position1, xieite::streams::Position position2) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/streams/position.hpp"

int main() {
    auto foo = xieite::streams::Position(25, 3);
    auto bar = xieite::streams::Position(16, 9);

    std::println("{}", foo == bar);
}
```
Output:
```
false
```
