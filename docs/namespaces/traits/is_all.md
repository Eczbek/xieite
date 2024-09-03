# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsAll\<\> \{\}
Defined in fragment [xieite:traits.IsAll](../../../src/traits/is_all.cpp)

&nbsp;

## [Description](../concepts/all.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
struct IsAll
: std::bool_constant<xieite::concepts::All<Type, Traits...>> {};
```

&nbsp;

## [Example](../concepts/all.md#Example)
