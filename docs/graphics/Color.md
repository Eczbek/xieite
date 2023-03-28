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
constexpr Color(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha = 255) noexcept;
```
```cpp
constexpr Color(std::uint32_t value) noexcept;
```

## Operators
```cpp
constexpr bool operator==(xieite::graphics::Color other) const noexcept;
```
(`operator!=` is defined implicitly)

## Other methods
```cpp
constexpr std::uint32_t value() noexcept;
```
