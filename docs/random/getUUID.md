# [xieite](../xieite.md)\:\:[random](../random.md)\:\:getUUID
Defined in header [<xieite/random/getUUID.hpp>](../../include/xieite/random/getUUID.hpp)

&nbsp;

## Description
Generates a UUID. Compile with `-luuid`

&nbsp;

## Synopsis
```cpp
inline std::string getUUID() noexcept;
```
#### Return type
- `std::string`

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/random/getUUID.hpp>

int main() {
    std::cout << xieite::random::getUUID() << '\n';
}
```
Very unlikely output:
```
bf59be9f-2e6d-4236-b456-e64161efd709
```
