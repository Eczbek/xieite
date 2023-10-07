# [xieite](../../xieite.md)\:\:[graphics](../../graphics.md)\:\:Canvas
Defined in header [<xieite/graphics/Canvas.hpp>](../../../include/xieite/graphics/Canvas.hpp)

&nbsp;

## Description
A canvas for drawing shapes to the terminal.

&nbsp;

## Synopses
#### 1)
```cpp
struct Canvas {
    xieite::geometry::Point center;
    xieite::geometry::Point radii;
    xieite::streams::StandardController controller;

    constexpr Canvas(xieite::geometry::Point, xieite::geometry::Point, xieite::streams::StandardController = xieite::system::terminal);

    void print(xieite::streams::Position) const;

    void clear();

    void draw(xieite::geometry::Point, const xieite::graphics::Color&);

    template<xieite::concepts::LinearShape LinearShape>
    void draw(const LinearShape&, const xieite::graphics::Color&);

    void draw(const xieite::geometry::Polygon&, const xieite::graphics::Color&)
};
```
##### Member variables
- canter
- radii
- controller
##### Member functions
- [Canvas](./structures/Canvas/1/operators/constructor.md)
- [print](./structures/Canvas/1/print.md)
- [clear](./structures/Canvas/1/clear.md)
- [draw](./structures/Canvas/1/draw.md)
