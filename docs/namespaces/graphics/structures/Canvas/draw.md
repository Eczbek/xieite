# [xieite](../../../../../xieite.md)\:\:[graphics](../../../../../graphics.md)\:\:[Color](../../../Color.md)\:\:print
Defined in header [<xieite/graphics/Color.hpp>](../../../../../../include/xieite/graphics/Color.hpp)

&nbsp;

## Description
Draws a shape on the canvas.

&nbsp;

## Synopses
#### 1)
```cpp
void print(xieite::geometry::Point point, const xieite::graphics::Color& color) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::LinearShape LinearShape>
void draw(const LinearShape& line, const xieite::graphics::Color& color) noexcept;
```
#### 1)
```cpp
void draw(const xieite::geometry::Polygon& polygon, const xieite::graphics::Color& color) noexcept;
```
