# [xieite](../../xieite.md)\:\:[metadata](../../metadata.md)\:\:compilationTimestamp
Defined in header [<xieite/metadata/compilation_timestamp.hpp>](../../../include/xieite/metadata/compilation_timestamp.hpp)

&nbsp;

## Description
Stores the time of compilation.

&nbsp;

## Synopsis
#### 1)
```cpp
static constexpr std::chrono::seconds compilationTimestamp = /* ... */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/metadata/compilation_timestamp.hpp"
#include "xieite/strings/timestamp.hpp"

int main() {
    std::println("{}", xieite::strings::timestamp(xieite::metadata::compilationTimestamp));
}
```
Possible output:
```
2024-01-15 23:51:50
```
