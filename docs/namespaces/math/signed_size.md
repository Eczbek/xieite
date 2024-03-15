# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:SignedSize
Defined in header [<xieite/math/signed_size.hpp>](../../../include/xieite/math/signed_size.hpp)

&nbsp;

## Description
A type alias for the signed version of `std::size_t`.

&nbsp;

## Synopsis
#### 1)
```cpp
using SignedSize = std::make_signed_t<std::size_t>;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/signed_size.hpp"
#include "xieite/types/name.hpp"

int main() {
    std::println("{}", xieite::types::name<xieite::math::SignedSize>);
}
```
Possible output:
```
long int
```
