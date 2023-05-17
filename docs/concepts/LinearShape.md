# [`xieite`](../../README.md)`::`[`concepts`](../../docs/concepts.md)`::LinearShape`
Defined in header [`<xieite/concepts/LinearShape.hpp>`](../../include/xieite/concepts/LinearShape.hpp)

<br/>

Specifies that type `Any` is a `xieite::geometry::Line`, `xieite::geometry::Ray`, or `xieite::geometry::Segment`.

<br/><br/>

## Synopsis

<br/>

```cpp
template<typename Any>
concept LinearShape = xieite::concepts::SameAsOneOf<Any, xieite::geometry::Line, xieite::geometry::Ray, xieite::geometry::Segment>;
```
### Template parameters
- `Any` - Any type
