# [`xieite`](../../../README.md)`::`[`graphics`](../../../docs/graphics.md)`::`[`Color`](../../../docs/graphics/Color.md)`::Color`
Defined in header [`<xieite/graphics/Color.hpp>`](../../../include/xieite/graphics/Color.hpp)

<br/>

Constructs a `xieite::graphics::Color`.

<br/><br/>

## Synopses

<br/>

```cpp
constexpr Color(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha = 255) noexcept;
```
### Parameters
- `red` - A `std::uint8_t` copy
- `green` - A `std::uint8_t` copy
- `blue` - A `std::uint8_t` copy
- `alpha` - A `std::uint8_t` copy, set to `255` by default

<br/>

```cpp
constexpr Color(std::uint32_t value) noexcept;
```
### Parameters
- `value` - A `std::uint32_t` copy to get RGBA values from by shifting
