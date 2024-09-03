# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsSameAsAny\<\> \{\}
Defined in fragment [xieite:traits.IsSameAsAny](../../../src/traits/is_same_as_any.cpp)

&nbsp;

## [Description](../concepts/same_as_any.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename First, typename... Rest>
struct IsSameAsAny
: std::bool_constant<xieite::concepts::SameAsAny<First, Rest...>> {};
```

&nbsp;

## [Example](../concepts/same_as_any.md#Example)
