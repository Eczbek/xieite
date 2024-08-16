# [xieite](../../../../../../xieite.md)\:\:[streams](../../../../../../streams.md)\:\:[Color<channels>](../../../../color.md)\:\:Color\(\)
Defined in header [<xieite/streams/color.hpp>](../../../../../../../include/xieite/streams/color.hpp)

&nbsp;

## Description
Constructs a `xieite::streams::Color<channels>`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::same_as<std::uint8_t>... Arguments>
requires(sizeof...(Arguments) == channels)
constexpr Color(Arguments... arguments) noexcept;
```
#### 2)
```cpp
constexpr Color(xieite::types::LeastInteger<xieite::bits::size<std::uint8_t> * channels> value = 0) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/streams/color.hpp"

int main() {
    auto color = xieite::streams::Color<3>(0xFF7F00);

    std::println("{} {} {}", color[0], color[1], color[2]);
}
```
Output:
```
false
```
