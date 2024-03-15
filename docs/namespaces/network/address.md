# [xieite](../../xieite.md)\:\:[network](../../network.md)\:\:Address \{\}
Defined in header [<xieite/network/address.hpp>](../../../include/xieite/network/address.hpp)

&nbsp;

## Description
A structure to represent an IPv6 address. For use on UNIX-like systems.

&nbsp;

## Synopsis
#### 1)
```cpp
struct Address {
    Address(const std::string& = "::", std::uint16_t = 1024);

    template<typename Self>
    std::conditional_t<std::is_const_v<Self>, const ::sockaddr*, ::sockaddr*> data(this Self&) noexcept;

    template<typename Self>
    std::conditional_t<std::is_const_v<Self>, const ::socklen_t*, ::socklen_t*> size(this Self&) noexcept;
};
```
##### Members
- [Address\(\)](./structures/address/1/operators/constructor.md)
- [data\(\)](./structures/address/1/data.md)
- [size\(\)](./structures/address/1/size.md)

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/network/address.hpp"

int main() {
    xieite::network::Address address;

    std::println("{}", *address.size());
}
```
Possible output:
```
28
```
