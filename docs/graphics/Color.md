# xieite::graphics::Color
Defined in header `<xieite/graphics/Color.hpp>`

<br/>

A simple struct for storing an RGBA value.

<br/><br/>

## Member objects
```cpp
std::uint8_t red;
```
```cpp
std::uint8_t green;
```
```cpp
std::uint8_t blue;
```
```cpp
std::uint8_t alpha;
```

## Constructors
```cpp
constexpr Color(const std::uint8_t red, const std::uint8_t green, const std::uint8_t blue, const std::uint8_t alpha = 255) noexcept;
```
```cpp
constexpr Color(const std::uint32_t value) noexcept;
```

## Operators
```cpp
constexpr bool operator==(const xieite::graphics::Color other) const noexcept;
```
(`operator!=` is defined implicitly)

## Other methods
```cpp
constexpr std::uint32_t value() noexcept;
```
