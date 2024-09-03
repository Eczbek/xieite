# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsSameAsAll\<\> \{\}
Defined in fragment [xieite:traits.IsSameAsAll](../../../src/traits/is_same_as_all.cpp)

&nbsp;

## [Description](../concepts/same_as_all.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename First, typename... Rest>
struct IsSameAsAll
: std::bool_constant<xieite::concepts::SameAsAll<First, Rest...>> {};
```

&nbsp;

## [Example](../concepts/same_as_all.md#Example)
