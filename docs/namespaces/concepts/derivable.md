# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Derivable\<\>
Defined in header [<xieite/concepts/derivable.hpp>](../../../include/xieite/concepts/derivable.hpp)

&nbsp;

## Description
Specifies that a type can be derived from. `Type_` must be a complete type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_>
concept Derivable = !std::is_final_v<Type_>;
```

&nbsp;

## [Example](https://en.cppreference.com/w/cpp/types/is_final#Example)
