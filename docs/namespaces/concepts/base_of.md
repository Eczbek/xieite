# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:BaseOf\<\>
Defined in fragment [xieite:concepts.BaseOf](../../../src/concepts/base_of.cpp)

&nbsp;

## Description
Specifies that a type is a base of another derived type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Base, typename Derived>
concept BaseOf = std::derived_from<Derived, Base>;
```

&nbsp;

## [Example](https://en.cppreference.com/w/cpp/concepts/derived_from#Example)
