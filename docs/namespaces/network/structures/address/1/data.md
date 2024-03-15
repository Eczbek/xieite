# [xieite](../../../../../xieite.md)\:\:[network](../../../../../network.md)\:\:[Address](../../../address.md)\:\:data\(\)
Defined in header [<xieite/network/address.hpp>](../../../../../../include/xieite/network/address.hpp)

&nbsp;

## Description
Returns some sort of address data?

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Self>
[[nodiscard]] std::conditional_t<std::is_const_v<Self>, const ::sockaddr*, ::sockaddr*> data(this Self&) noexcept;
```

&nbsp;

## [Example](./operators/constructor.md#Example)
