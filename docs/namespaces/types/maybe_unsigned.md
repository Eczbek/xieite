# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:MaybeUnsigned
Defined in header [<xieite/types/maybe_unsigned.hpp>](../../../include/xieite/types/maybe_unsigned.hpp)

&nbsp;

## Description
// TODO

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
using MaybeUnsigned = std::conditional_t<std::signed_integral<Type>, std::make_unsigned<Type>, std::type_identity<Type>>::type;
```
