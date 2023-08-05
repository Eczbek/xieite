# [xieite](../xieite.md)::[concepts](../concepts.md)::LinearShape
Defined in header [<xieite/concepts/LinearShape.hpp>](../../include/xieite/concepts/LinearShape.hpp)

<br/>

Specifies that a type is a `xieite::geometry::Line`, `xieite::geometry::Ray`, or `xieite::geometry::Segment`

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept LinearShape = xieite::concepts::SameAsAny<Any, xieite::geometry::Line, xieite::geometry::Ray, xieite::geometry::Segment>;
```
### Template parameters
- `Any` - Any type
