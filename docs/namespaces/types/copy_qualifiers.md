# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:CopyQualifiers\<\>
Defined in header [<xieite/types/copy_qualifiers.hpp>](../../../include/xieite/types/copy_qualifiers.hpp)

&nbsp;

## Description
Copies the constness, volatileness, and reference type of `Source` to `Target`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename Target>
using CopyQualifiers = /* ... */;
```

&nbsp;

## Example
```cpp
#include <concepts>
#include <print>
#include "xieite/types/copy_qualifiers.hpp"

int main() {
    std::println("{}", std::same_as<int* const volatile&&, xieite::types::CopyQualifiers<volatile const float&&, int*&>>);
}
```
Output:
```
true
```
