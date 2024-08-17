# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:CopyReference\<\>
Defined in header [<xieite/types/copy_reference.hpp>](../../../include/xieite/types/copy_reference.hpp)

&nbsp;

## Description
Copies the reference type of `Source` to `Target`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename Target>
using CopyReference = /* ... */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/copy_reference.hpp"
#include "xieite/types/name.hpp"

int main() {
    std::println("{}", xieite::types::name<xieite::types::CopyReference<float, int>>);
    std::println("{}", xieite::types::name<xieite::types::CopyReference<float, int&>>);
    std::println("{}", xieite::types::name<xieite::types::CopyReference<float, int&&>>);
    std::println("{}", xieite::types::name<xieite::types::CopyReference<float&, int>>);
    std::println("{}", xieite::types::name<xieite::types::CopyReference<float&, int&>>);
    std::println("{}", xieite::types::name<xieite::types::CopyReference<float&, int&&>>);
    std::println("{}", xieite::types::name<xieite::types::CopyReference<float&&, int>>);
    std::println("{}", xieite::types::name<xieite::types::CopyReference<float&&, int&>>);
    std::println("{}", xieite::types::name<xieite::types::CopyReference<float&&, int&&>>);
}
```
Possible output:
```
int
int
int
int&
int&
int&
int&&
int&&
int&&
```
