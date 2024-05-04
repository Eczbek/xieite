# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsDerivedFrom\<\> \{\}
Defined in header [<xieite/traits/is_derived_from.hpp>](../../../include/xieite/traits/is_derived_from.hpp)

&nbsp;

## [Description](https://en.cppreference.com/w/cpp/concepts/derived_from)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Derived_, typename Base_>
struct IsDerivedFrom
: std::bool_constant<std::derived_from<Derived_, Base_>> {};
```

&nbsp;

## [Example](https://en.cppreference.com/w/cpp/concepts/derived_from#Example)
