# `xieite::concepts::LinearShape`
Defined in header [`<xieite/concepts/LinearShape.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/concepts/LinearShape.hpp)

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
