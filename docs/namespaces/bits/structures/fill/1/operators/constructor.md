# [xieite](../../../../../../xieite.md)\:\:[bits](../../../../../../bits.md)\:\:[Fill](../../../../fill.md)\:\:Fill\<\>\(\)
Defined in header [<xieite/bits/fill.hpp>](../../../../../../../include/xieite/bits/fill.hpp)

&nbsp;

## Description
Constructs a `xieite::bits::Fill` thingamabob.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral_>
constexpr Fill(Integral_ value) noexcept;
```
Accepts any integral type until I think of a reason for why it shouldn't.

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/bits/fill.hpp"

int main() {
    auto fill = xieite::bits::Fill(-1);

    std::println("{}", fill.value);
}
```
Output:
```
255
```
