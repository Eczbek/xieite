# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:CopyAssignable
Defined in header [<xieite/concepts/CopyAssignable.hpp>](../../../include/xieite/concepts/CopyAssignable.hpp)

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
