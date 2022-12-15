# xieite::console::Canvas
Declared in `<xieite/console/Canvas.hpp>`

<br/>

A class for storing and operating on a 2D text-based canvas.

<br/><br/>

## Constructor
```cpp
constexpr Canvas(const int width, const int height, const xieite::graphics::Color color = xieite::graphics::colors::white) noexcept;
```

## Methods
```cpp
constexpr void draw(const int x, const int y, const xieite::graphics::Color color) noexcept;
```
```cpp
constexpr std::string string(const int top = 0, const int left = 0) const noexcept;
```

<br/><br/>

## Example
[Snake Game](https://github.com/Eczbek/cpp-snake)
