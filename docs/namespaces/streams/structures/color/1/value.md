# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[Color<channels_>](../../../color.md)\:\:value\(\)
Defined in header [<xieite/streams/color.hpp>](../../../../../../include/xieite/streams/color.hpp)

&nbsp;

## Description
Shifts and adds color values together to create a single value.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr xieite::types::LeastInteger<xieite::bits::size<std::uint8_t> * channels_> value() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/stringify.hpp"
#include "xieite/streams/color.hpp"

int main() {
    auto color = xieite::streams::Color<3>(255, 127, 0);

    std::println("{}", xieite::math::stringify(color.value(), 16));
}
```
Output:
```
FF7F00
```
