# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:ConvertibleFrom\<\>
Defined in fragment [xieite:concepts.ConvertibleFrom](../../../src/concepts/convertible_from.cpp)

&nbsp;

## Description
Specifies that a type can be converted from another type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Target, typename Source>
concept ConvertibleFrom = std::convertible_to<Source, Target>;
```

&nbsp;

## [Example](https://en.cppreference.com/w/cpp/concepts/convertible_to#Example)
