# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:CopyAssignable
Defined in header [<xieite/concepts/copy_assignable.hpp>](../../../include/xieite/concepts/copy_assignable.hpp)

&nbsp;

## Description
Specifies that a type is copy-assignable.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
concept CopyAssignable = std::is_copy_assignable_v<Type>;
```

&nbsp;

## [Example](https://en.cppreference.com/w/cpp/types/is_copy_assignable#Example)
