# [xieite](../../../../../../xieite.md)\:\:[streams](../../../../../../streams.md)\:\:[Color](../../../../color.md)\:\:operator==\(\)
Defined in header [<xieite/streams/color.hpp>](../../../../../../../include/xieite/streams/color.hpp)

&nbsp;

## Description
Compares two `xieite::streams::Colors`.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr bool operator==(const xieite::streams::Color& color1, const xieite::streams::Color& color2) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/streams/color.hpp"

int main() {
    auto color1 = xieite::streams::Color(255, 127, 0);
    auto color2 = xieite::streams::Color(63, 0, 191);

    std::println("{}", color1 == color2);
}
```
Output:
```
false
```
