# xieite::graphics::Color
Defined in header `<xieite/graphics/Color.hpp>`

<br/>

A simple struct for storing an RGB value.

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

## Constructors
```cpp
constexpr Color(const std::uint8_t red = 0, const std::uint8_t green = 0, const std::uint8_t blue = 0) noexcept;
```

## Operators
```cpp
constexpr bool operator==(const xieite::graphics::Color other) const noexcept;
```
```cpp
constexpr bool operator!() const noexcept;
```
(`operator!=` is defined implicitly)
