# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:AllOf
Defined in header [<xieite/concepts/AllOf.hpp>](../../include/xieite/concepts/AllOf.hpp)

&nbsp;

## Description
Specifies that a type satisfies all of several type traits.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
concept AllOf = (... && requires {
	{ Traits<Type>::value } -> std::convertible_to<bool>;
}) && (... && Traits<Type>::value);
```
