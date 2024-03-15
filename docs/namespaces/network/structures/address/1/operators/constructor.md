# [xieite](../../../../../../xieite.md)\:\:[network](../../../../../../network.md)\:\:[Address](../../../../address.md)\:\:Address\(\)
Defined in header [<xieite/network/address.hpp>](../../../../../../../include/xieite/network/address.hpp)

&nbsp;

## Description
Constructs a `xieite::network::Address`.

&nbsp;

## Synopsis
#### 1)
```cpp
Address(const std::string& host = "::");
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/network/address.hpp"

int main() {
    auto address = xieite::network::Address("::1");

    for (char byte : address.data()->sa_data) {
        std::println("{}", static_cast<int>(byte));
    }
}
```
Possible output:
```
199
233
134
114
0
0
0
0
0
0
0
0
0
0
```
