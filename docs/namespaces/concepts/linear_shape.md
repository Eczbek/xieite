# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:LinearShape
Defined in header [<xieite/concepts/linear_shape.hpp>](../../../include/xieite/concepts/linear_shape.hpp)

&nbsp;

## Description
Specifies that a type is one of `xieite::geometry::Line`, `xieite::geometry::Ray`, and `xieite::geometry::Segment`.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
concept LinearShape = xieite::concepts::SameAsAnyOf<Type, xieite::geometry::Line, xieite::geometry::Ray, xieite::geometry::Segment>;
```
