# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsSimilarToAny\<\> \{\}
Defined in fragment [xieite:traits.IsSimilarToAny](../../../src/traits/is_similar_to_any.cpp)

&nbsp;

## [Description](../concepts/similar_to_any.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename First, typename... Rest>
struct IsSimilarToAny
: std::bool_constant<xieite::concepts::SimilarToAny<First, Rest...>> {};
```

&nbsp;

## [Example](../concepts/similar_to_any.md#Example)
