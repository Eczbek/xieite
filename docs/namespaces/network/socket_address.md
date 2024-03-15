# [xieite](../../xieite.md)\:\:[network](../../network.md)\:\:SocketAddress \{\}
Defined in header [<xieite/network/socket_address.hpp>](../../../include/xieite/network/socket_address.hpp)

&nbsp;

## Description
A structure to represent a socket address. For use on UNIX-like systems.

&nbsp;

## Synopsis
#### 1)
```cpp
struct SocketAddress
: xieite::network::Address {
    SocketAddress(const std::string& = "::", std::uint16_t = 0);
};
```
##### Members
- [SocketAddress](./structures/socket_address/1/operators/constructor.md)
