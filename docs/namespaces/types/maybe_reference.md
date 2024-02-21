# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:MaybeReference
Defined in header [<xieite/types/maybe_reference.hpp"](../../../include/xieite/types/maybe_reference.hpp)

&nbsp;

## Description
A type for automatically determining if a type should be taken by copy or by reference.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
using MaybeReference = std::conditional_t<(sizeof(Type) > sizeof(std::size_t)), const Type&, const Type>;
```
