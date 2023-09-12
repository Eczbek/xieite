# [xieite](../xieite.md)\:\:[graphics](../graphics.md)\:\:Color
Defined in header [<xieite/graphics/Color.hpp>](../../include/xieite/graphics/Color.hpp)

&nbsp;

## Description
A simple class for storing an RGBA value.

&nbsp;

## Synopses
#### 1)
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
##### Member variables
- red
- green
- blue
- alpha
##### Member functions
- [Color](./Color/1/operators/constructor.md)
- [operator==](./Color/1/operators/equal.md)
- [value](./Color/1/value.md)
