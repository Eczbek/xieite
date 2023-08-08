# [xieite](../xieite.md)\:\:[graphics](../graphics.md)\:\:Color
Defined in header [<xieite/graphics/Color.hpp>](../../include/xieite/graphics/Color.hpp)

&nbsp;

## Description
A simple class for storing an RGBA value

&nbsp;

## Synopsis
```cpp
struct Color {
    std::uint8_t red;
    std::uint8_t green;
    std::uint8_t blue;
    std::uint8_t alpha;

    constexpr Color(std::uint8_t = 0, std::uint8_t = 0, std::uint8_t = 0, std::uint8_t = std::numeric_limits<std::uint8_t>::max());

    constexpr Color(std::uint32_t);

    constexpr bool operator==(const xieite::graphics::Color&) const;

    constexpr std::uint32_t value();
};
```
#### Public members
## Contents
|- red
|- green
|- blue
|- alpha
|- <a href="./Color/constructor.md">Color</a>
|- <a href="./Color/operatorEquals.md">operator==</a>
`- <a href="./Color/value.md">value</a>
