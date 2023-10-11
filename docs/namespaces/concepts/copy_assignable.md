# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:CopyAssignable
Defined in header [<xieite/concepts/copy_assignable.hpp>](../../../include/xieite/concepts/copy_assignable.hpp)

&nbsp;

## Description
Specifies that a type is copy-assignable.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
concept CopyAssignable = std::is_copy_assignable_v<Type>;
```