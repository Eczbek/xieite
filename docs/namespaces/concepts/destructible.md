# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Destructible\<\>
Defined in header [<xieite/concepts/destructible.hpp>](../../../include/xieite/concepts/destructible.hpp)

&nbsp;

## Description
Specifies that a type is destructible.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept Destructible = std::is_destructible_v<Type>;
```

&nbsp;

## [Example](https://en.cppreference.com/w/cpp/types/is_destructible#Example)
