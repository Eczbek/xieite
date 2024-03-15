# [xieite](../../../../../xieite.md)\:\:[network](../../../../../network.md)\:\:[Address](../../../address.md)\:\:size\(\)
Defined in header [<xieite/network/address.hpp>](../../../../../../include/xieite/network/address.hpp)

&nbsp;

## Description
Returns a pointer to the address size.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Self>
[[nodiscard]] std::conditional_t<std::is_const_v<Self>, const ::socklen_t*, ::socklen_t*> size(this Self&) noexcept
```

&nbsp;

## [Example](../../../address.md#Example)
