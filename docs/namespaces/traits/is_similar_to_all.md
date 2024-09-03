# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsSimilarToAll\<\> \{\}
Defined in fragment [xieite:traits.IsSimilarToAll](../../../src/traits/is_similar_to_all.cpp)

&nbsp;

## [Description](../concepts/similar_to_all.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename First, typename... Rest>
struct IsSimilarToAll
: std::bool_constant<xieite::concepts::SimilarToAll<First, Rest...>> {};
```

&nbsp;

## [Example](../concepts/similar_to_all.md#Example)
