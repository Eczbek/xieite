# [xieite](../../xieite.md)\:\:[streams](../../streams.md)\:\:Color
Defined in header [<xieite/streams/color.hpp>](../../../include/xieite/streams/color.hpp)

&nbsp;

## Description
A simple class for storing an RGB value.

&nbsp;

## Synopsis
#### 1)
```cpp
struct Color {
    std::uint8_t red;
    std::uint8_t green;
    std::uint8_t blue;

    constexpr Color(std::uint8_t = 0, std::uint8_t = 0, std::uint8_t = 0);

    constexpr Color(std::uint32_t);

    friend constexpr bool operator==(const xieite::streams::Color&, const xieite::streams::Color&);

    constexpr std::uint32_t value();
};
```
##### Members
- red
- green
- blue
- alpha
- [Color](./structures/color/1/operators/constructor.md)
- [operator==](./structures/color/1/operators/equal.md)
- [value](./structures/color/1/value.md)
