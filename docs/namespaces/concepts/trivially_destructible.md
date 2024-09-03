# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:TriviallyDestructible\<\>
Defined in fragment [xieite:concepts.TriviallyDestructible](../../../src/concepts/trivially_destructible.cpp)

&nbsp;

## Description
Specifies that a type is trivially destructible.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept TriviallyDestructible = std::is_trivially_destructible_v<Type>;
```

&nbsp;

## [Example](https://en.cppreference.com/w/cpp/types/is_destructible#Example)
