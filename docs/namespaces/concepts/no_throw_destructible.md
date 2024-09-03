# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NoThrowDestructible\<\>
Defined in fragment [xieite:concepts.NoThrowDestructible](../../../src/concepts/no_throw_destructible.cpp)

&nbsp;

## Description
Specifies that a type is destructible without throwing exceptions.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept NoThrowDestructible = std::is_nothrow_destructible_v<Type>;
```

&nbsp;

## [Example](https://en.cppreference.com/w/cpp/types/is_destructible#Example)
