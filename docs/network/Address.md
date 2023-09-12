# [xieite](../xieite.md)\:\:[network](../network.md)\:\:Address
Defined in header [<xieite/network/Address.hpp>](../../include/xieite/network/Address.hpp)

&nbsp;

## Description
A structure to represent an IPv6 address.

&nbsp;

## Synopses
#### 1)
```cpp
struct Address {
    Address(const std::string& = "::", const std::uint16_t = 1024);

    ::sockaddr* data();

    const ::sockaddr* data() const;

    ::socklen_t* size();

    const ::socklen_t* size() const;
};
```
##### Member functions
- [Address](./Address/1/operators/constructor.md)
- [data](./Address/1/data.md)
- [size](./Address/1/size.md)
