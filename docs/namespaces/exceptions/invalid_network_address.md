# [xieite](../../xieite.md)\:\:[exceptions](../../exceptions.md)\:\:InvalidNetworkAddress
Defined in header [<xieite/exceptions/invalid_network_address.hpp>](../../../include/xieite/exceptions/invalid_network_address.hpp)

&nbsp;

An exception type that indicates the creation of an invalid network address. Extends `xieite::exceptions::Unspecified`.

&nbsp;

## Synopsis
#### 1)
```cpp
struct InvalidNetworkAddress
: xieite::exceptions::Unspecified {
    InvalidNetworkAddress(std::string_view = "");
};
```
##### Member functions
- [InvalidNetworkAddress](./structures/invalid_network_address/1/operators/constructor.md)

&nbsp;

## Example
```cpp
#include "xieite/exceptions/invalid_network_address.hpp"

int main() {
    throw xieite::exceptions::InvalidNetworkAddress("Something");
}
```
Possible output:
```
terminate called after throwing an instance of 'xieite::exceptions::InvalidNetworkAddress'
  what():  Something
Aborted (core dumped)
```
