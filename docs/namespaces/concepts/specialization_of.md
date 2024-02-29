# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:SpecializationOf
Defined in header [<xieite/concepts/specialization_of.hpp>](../../../include/xieite/concepts/specialization_of.hpp)

&nbsp;

## Description
Specifies that a type is a specialization of a template. To be deprecated once `std::specialization_of` is standardized.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, template<typename...> typename Template>
concept SpecializationOf = xieite::traits::IsSpecializationOf<std::remove_cv_t<Type>, Template>::value;
```

&nbsp;

## [Example](https://en.cppreference.com/w/cpp/types/is_scoped_enum#Example)