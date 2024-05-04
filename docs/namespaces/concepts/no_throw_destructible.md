# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NoThrowDestructible\<\>
Defined in header [<xieite/concepts/no_throw_destructible.hpp>](../../../include/xieite/concepts/no_throw_destructible.hpp)

&nbsp;

## Description
Specifies that a type is destructible without throwing exceptions.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_>
concept NoThrowDestructible = std::is_nothrow_destructible_v<Type_>;
```

&nbsp;

## [Example](https://en.cppreference.com/w/cpp/types/is_destructible#Example)
