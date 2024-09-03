# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsHashable\<\> \{\}
Defined in fragment [xieite:traits.IsHashable](../../../src/traits/is_hashable.cpp)

&nbsp;

## [Description](../concepts/hashable.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, typename Hasher = std::hash<Type>>
struct IsHashable
: std::bool_constant<xieite::concepts::Hashable<Type, Hasher>> {};
```

&nbsp;

## [Example](../concepts/hashable.md#Example)
