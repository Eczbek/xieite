# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Decayed
Defined in header [<xieite/concepts/decayed.hpp>](../../../include/xieite/concepts/decayed.hpp)

&nbsp;

## Description
Specifies that a type is decayed.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept Decayed = std::same_as<Type, std::decay_t<Type>>;
```

&nbsp;

## [Example](https://en.cppreference.com/w/cpp/types/decay#Example)
