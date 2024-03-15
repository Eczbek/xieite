# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:MaybeSigned
Defined in header [<xieite/types/maybe_signed.hpp>](../../../include/xieite/types/maybe_signed.hpp)

&nbsp;

## Description
// TODO

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
using MaybeSigned = std::conditional_t<xieite::concepts::UnsignedInteger<Type>, std::make_signed<Type>, std::type_identity<Type>>::type;
```
