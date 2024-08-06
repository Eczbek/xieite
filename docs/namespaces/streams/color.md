# [xieite](../../xieite.md)\:\:[streams](../../streams.md)\:\:Color\<\> \{\}
Defined in header [<xieite/streams/color_3.hpp>](../../../include/xieite/streams/color_3.hpp)

&nbsp;

## Description
A simple class for storing an RGB(A) value.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t channels_ = 3>
struct Color {
    std::array<std::uint8_t, channels_> data;

    template<std::same_as<std::uint8_t>... Arguments_>
    requires(sizeof...(Arguments_) == channels_)
    constexpr Color(Arguments_...) noexcept;

    constexpr Color(xieite::types::LeastInteger<xieite::bits::size<std::uint8_t> * channels_> = 0) noexcept;

    friend constexpr bool operator==(const xieite::streams::Color<channels_>&, const xieite::streams::Color<channels_>&) noexcept = default;

    template<typename Self>
    constexpr decltype(auto) operator[](this Self&&, std::size_t) noexcept;

    constexpr xieite::types::LeastInteger<xieite::bits::size<std::uint8_t> * channels_> value() const noexcept;
};
```
- data
- [Color\(\)](./structures/color/1/operators/constructor.md)
- [operator\[\]\(\)](./structures/color/1/operators/array_subscript.md)
- [value\(\)](./structures/color/1/value.md)

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/streams/color.hpp"

int main() {
    auto color = xieite::streams::Color<3>(255, 127, 0);

    std::println("{} {} {}", color[0], color[1], color[2]);
}
```
Output:
```
255 127 0
```
