# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:DefaultConstructible\<\>
Defined in fragment [xieite:concepts.DefaultConstructible](../../../src/concepts/default_constructible.cpp)

&nbsp;

## Description
Specifies that a type is default-constructible.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept DefaultConstructible = std::is_default_constructible_v<Type>;
```

&nbsp;

## [Example](https://en.cppreference.com/w/cpp/types/is_default_constructible#Example)
