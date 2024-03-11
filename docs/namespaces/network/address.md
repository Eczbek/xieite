# [xieite](../../xieite.md)\:\:[network](../../network.md)\:\:Address
Defined in header [<xieite/network/address.hpp>](../../../include/xieite/network/address.hpp)

&nbsp;

## Description
A structure to represent an IPv6 address.

&nbsp;

## Synopsis
#### 1)
```cpp
struct Address {
    Address(const std::string& = "::", const std::uint16_t = 1024);

    const sockaddr* data() const;

    sockaddr* data();

    const socklen_t* size() const;

    socklen_t* size();
};
```
- [Address](./structures/address/1/operators/constructor.md)
- [data](./structures/address/1/data.md)
- [size](./structures/address/1/size.md)
