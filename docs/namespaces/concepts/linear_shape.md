# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:LinearShape
Defined in header [<xieite/concepts/linear_shape.hpp>](../../../include/xieite/concepts/linear_shape.hpp)

&nbsp;

## Description
Specifies that a type is one of `xieite::geometry::Line`, `xieite::geometry::Ray`, or `xieite::geometry::Segment`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, typename Number = double>
concept LinearShape = xieite::concepts::SameAsAny<std::remove_cvref_t<Type>, xieite::geometry::Line<Number>, xieite::geometry::Ray<Number>, xieite::geometry::Segment<Number>>;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/concepts/linear_shape.hpp"
#include "xieite/geometry/line.hpp"

int main() {
    std::println("{}", xieite::concepts::LinearShape<xieite::geometry::Line<>>);
    std::println("{}", xieite::concepts::LinearShape<int>);
}
```
Output:
```
true
false
```
