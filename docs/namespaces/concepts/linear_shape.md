# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:LinearShape\<\>
Defined in fragment [xieite:concepts.LinearShape](../../../src/concepts/linear_shape.cpp)

&nbsp;

## Description
Specifies that a type is one of `xieite::geometry::Line`, `xieite::geometry::Ray`, or `xieite::geometry::Segment`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, typename Arithmetic = double>
concept LinearShape = xieite::concepts::Arithmetic<Arithmetic> && xieite::concepts::SameAsAny<std::remove_cvref_t<Type>, xieite::geometry::Line<Arithmetic>, xieite::geometry::Ray<Arithmetic>, xieite::geometry::Segment<Arithmetic>>;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

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
