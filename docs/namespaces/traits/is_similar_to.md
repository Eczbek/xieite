# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsSimilarTo\<\> \{\}
Defined in fragment [xieite:traits.IsSimilarTo](../../../src/traits/is_similar_to.cpp)

&nbsp;

## [Description](../concepts/similar_to.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename First, typename Second>
struct IsSimilarTo
: std::bool_constant<xieite::concepts::SimilarTo<First, Second>> {};
```

&nbsp;

## [Example](../concepts/similar_to.md#Example)
