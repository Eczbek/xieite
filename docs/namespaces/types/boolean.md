# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:Boolean \{\}
Defined in header [<xieite/types/boolean.hpp>](../../../include/xieite/types/boolean.hpp)

&nbsp;

## Description
An enumeration of boolean values.

&nbsp;

## Synopsis
#### 1)
```cpp
enum struct Boolean
: bool {
    False = false,
    True = true
};
```

&nbsp;

## Example
```cpp
#include <cstdint>
#include <print>
#include <vector>
#include "xieite/types/boolean.hpp"

int main() {
    std::vector<xieite::types::Boolean> data;

    data.push_back(static_cast<xieite::types::Boolean>(true));

    std::println("{}", reinterpret_cast<std::uintptr_t>(static_cast<void*>(&data[0])));
}
```
Possible output:
```
1d7d2b0
```
