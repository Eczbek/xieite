# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:MaybeSigned
Defined in header [<xieite/types/maybe_signed.hpp>](../../../include/xieite/types/maybe_signed.hpp)

&nbsp;

## Description
An alias to an optionally signed integral type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Integral Integral_, bool signed_>
using MaybeSigned = std::conditional_t<signed_, std::make_signed<Integral_>, std::make_unsigned<Integral_>>::type;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/maybe_signed.hpp"
#include "xieite/types/name.hpp"

int main() {
    std::println("{}", xieite::types::name<xieite::types::MaybeSigned<int, true>>);
    std::println("{}", xieite::types::name<xieite::types::MaybeSigned<int, false>>);
}
```
Possible output:
```
int
unsigned int
```
