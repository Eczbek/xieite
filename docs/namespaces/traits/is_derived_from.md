# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsDerivedFrom\<\> \{\}
Defined in fragment [xieite:traits.IsDerivedFrom](../../../src/traits/is_derived_from.cpp)

&nbsp;

## [Description](https://en.cppreference.com/w/cpp/concepts/derived_from)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Derived, typename Base>
struct IsDerivedFrom
: std::bool_constant<std::derived_from<Derived, Base>> {};
```

&nbsp;

## [Example](https://en.cppreference.com/w/cpp/concepts/derived_from#Example)
