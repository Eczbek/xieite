# [xieite](../../xieite.md)\:\:[graphics](../../graphics.md)\:\:[Color](../Color.md)\:\:Color
Defined in header [<xieite/graphics/Color.hpp>](../../../include/xieite/graphics/Color.hpp)

&nbsp;

## Description
Constructs a `xieite::graphics::Color`

&nbsp;

## Synopses

&nbsp;

```cpp
constexpr Color(std::uint8_t red = 0, std::uint8_t green = 0, std::uint8_t blue = 0, std::uint8_t alpha = std::numeric_limits<std::uint8_t>::max()) noexcept;
```
#### Function parameters
- `red` - A `std::uint8_t`, set to `0` by default
- `green` - A `std::uint8_t`, set to `0` by default
- `blue` - A `std::uint8_t`, set to `0` by default
- `alpha` - A `std::uint8_t`, set to `std::numeric_limits<std::uint8_t>::max()` by default

&nbsp;

```cpp
constexpr Color(std::uint32_t value) noexcept;
```
#### Function parameters
- `value` - A `std::uint32_t` to get RGBA values from by shifting
