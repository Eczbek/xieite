# [xieite](../../xieite.md)::[graphics](../../graphics.md)::[Color](../Color.md)::Color
Defined in header [<xieite/graphics/Color.hpp>](../../../include/xieite/graphics/Color.hpp)

<br/>

Constructs a `xieite::graphics::Color`

<br/><br/>

## Synopses

<br/><br/>

```cpp
constexpr Color(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha = std::numeric_limits<std::uint8_t>::max()) noexcept;
```
### Parameters
- `red` - A `std::uint8_t`
- `green` - A `std::uint8_t`
- `blue` - A `std::uint8_t`
- `alpha` - A `std::uint8_t`, set to `std::numeric_limits<std::uint8_t>::max()` by default

<br/><br/>

```cpp
constexpr Color(std::uint32_t value) noexcept;
```
### Parameters
- `value` - A `std::uint32_t` to get RGBA values from by shifting
