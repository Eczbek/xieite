# [xieite](../../../../../../xieite.md)\:\:[exceptions](../../../../../../exceptions.md)\:\:[InvalidNetworkAddress](../../../../invalid_network_address.md)\:\:InvalidNetworkAddress
Defined in header [<xieite/exceptions/invalid_network_address.hpp>](../../../../../../../include/xieite/exceptions/invalid_network_address.hpp)

&nbsp;

## Description
Constructs a `xieite::exceptions::InvalidNetworkAddress`.

## Synopsis
#### 1)
```cpp
InvalidNetworkAddress(std::string_view message = "") noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/exceptions/invalid_network_address.hpp"

int main() {
    xieite::exceptions::InvalidNetworkAddress exception;

    std::println("{}", exception.what());
}
```
Output:
```

```
