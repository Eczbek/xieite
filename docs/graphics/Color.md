# [`xieite`](../../README.md)`::`[`graphics`](../../docs/graphics.md)`::Color`
Defined in header [`<xieite/graphics/Color.hpp>`](../../include/xieite/graphics/Color.hpp)

<br/>

A simple class for storing an RGBA value.

<br/><br/>

## Synopsis

<br/>

```cpp
struct Color final {
	std::uint8_t red;
	std::uint8_t green;
	std::uint8_t blue;
	std::uint8_t alpha;


	constexpr Color(std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t = std::numeric_limits<std::uint8_t>::max());

	constexpr Color(std::uint32_t);

	constexpr bool operator==(const xieite::graphics::Color&) const;

	constexpr std::uint32_t value();
};
```
### Member objects
- `red` - A `std::uint8_t`
- `green` - A `std::uint8_t`
- `blue` - A `std::uint8_t`
- `alpha` - A `std::uint8_t`
### Member functions
- [`Color`](../../docs/graphics/Color/constructor.md)
- [`operator==`](../../docs/graphics/Color/operatorEquals.md)
- [`value`](../../docs/graphics/Color/value.md)
