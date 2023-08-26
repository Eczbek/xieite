# [xieite](../xieite.md)\:\:[network](../network.md)\:\:Protocol
Defined in header [<xieite/network/Protocol.hpp>](../../include/xieite/network/Protocol.hpp)

&nbsp;

## Description
An enumeration of network protocol things.

&nbsp;

## Synopses
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
