# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:TriviallyDestructible\<\>
Defined in header [<xieite/concepts/trivially_destructible.hpp>](../../../include/xieite/concepts/trivially_destructible.hpp)

&nbsp;

## Description
Specifies that a type is trivially destructible.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_>
concept TriviallyDestructible = std::is_trivially_destructible_v<Type_>;
```

&nbsp;

## [Example](https://en.cppreference.com/w/cpp/types/is_destructible#Example)
