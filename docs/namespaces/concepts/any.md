# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Any
Defined in header [<xieite/concepts/any.hpp>](../../../include/xieite/concepts/any.hpp)

&nbsp;

## Description
Specifies that a type satisfies at least one of several type traits.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
concept Any = (... && requires {
    { Traits<Type>::value } -> std::convertible_to<bool>;
}) && (... || Traits<Type>::value);
```
