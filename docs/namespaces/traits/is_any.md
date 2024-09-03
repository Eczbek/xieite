# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsAny\<\> \{\}
Defined in fragment [xieite:traits.IsAny](../../../src/traits/is_any.cpp)

&nbsp;

## [Description](../concepts/any.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
struct IsAny
: std::bool_constant<xieite::concepts::Any<Type, Traits...>> {};
```

&nbsp;

## [Example](../concepts/any.md#Example)
