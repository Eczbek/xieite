# [xieite](../../xieite.md)\:\:[network](../../network.md)\:\:Protocol \{\}
Defined in header [<xieite/network/protocol.hpp>](../../../include/xieite/network/protocol.hpp)

&nbsp;

## Description
An enumeration of network protocol types. For use on UNIX-like systems.

&nbsp;

## Synopsis
#### 1)
```cpp
enum struct Protocol
: int {
    Default = 0,
    ICMPv4 = IPPROTO_ICMP,
    ICMPv6 = IPPROTO_ICMPV6,
    IPv4 = IPPROTO_IP,
    IPv6 = IPPROTO_IPV6,
    Raw = IPPROTO_RAW,
    TCP = IPPROTO_TCP,
    UDP = IPPROTO_UDP
};
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/network/protocol.hpp"

int main() {
    std::println("{}", static_cast<int>(xieite::network::Protocol::IPv6));
}
```
Possible output:
```
41
```
