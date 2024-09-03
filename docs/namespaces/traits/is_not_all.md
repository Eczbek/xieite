# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNotAll\<\> \{\}
Defined in fragment [xieite:traits.IsNotAll](../../../src/traits/is_not_all.cpp)

&nbsp;

## [Description](../concepts/not_all.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
struct IsNotAll
: std::bool_constant<xieite::concepts::NotAll<Type, Traits...>> {};
```

&nbsp;

## [Example](../concepts/not_all.md#Example)
