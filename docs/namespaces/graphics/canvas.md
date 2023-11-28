# [xieite](../../xieite.md)\:\:[graphics](../../graphics.md)\:\:Canvas
Defined in header [<xieite/graphics/canvas.hpp>](../../../include/xieite/graphics/canvas.hpp)

&nbsp;

## Description
A canvas for drawing shapes and possibly printing to the terminal.

&nbsp;

## Synopses
#### 1)
```cpp
struct Canvas {
    xieite::geometry::Point center;
    xieite::geometry::Point radii;

    constexpr Canvas(xieite::geometry::Point, xieite::geometry::Point);

    void print(xieite::streams::StandardHandle, xieite::streams::Position = xieite::streams::Position(0, 0)) const;

    constexpr void clear();

    constexpr void draw(xieite::geometry::Point, const xieite::graphics::Color&);

    template<xieite::concepts::LinearShape LinearShape>
    constexpr void draw(const LinearShape&, const xieite::graphics::Color&);

    constexpr void draw(const xieite::geometry::Polygon&, const xieite::graphics::Color&)
};
```
##### Member variables
- canter
- radii
##### Member functions
- [Canvas](./structures/canvas/1/operators/constructor.md)
- [print](./structures/canvas/1/print.md)
- [clear](./structures/canvas/1/clear.md)
- [draw](./structures/canvas/1/draw.md)
