# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:ConditionallySigned
Defined in header [<xieite/types/conditionally_signed.hpp>](../../../include/xieite/types/conditionally_signed.hpp)

&nbsp;

## Description
// TODO

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Integer Integer, bool sign>
using ConditionallySigned = std::conditional_t<sign, std::make_signed_t<Integer>, std::make_unsigned_t<Integer>>;
```
