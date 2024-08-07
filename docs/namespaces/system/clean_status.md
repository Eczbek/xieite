# [xieite](../../xieite.md)\:\:[system](../../system.md)\:\:cleanStatus\(\)
Defined in header [<xieite/system/clean_status.hpp>](../../../include/xieite/system/clean_status.hpp)

&nbsp;

## Description
Cleans the exit status code of a process.

&nbsp;

## Synopsis
#### 1)
```cpp
inline int cleanStatus(int status) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/system/clean_status.hpp"

int main() {
    std::println("{}", xieite::system::cleanStatus(16384));
}
```
Possible output:
```
64
```
