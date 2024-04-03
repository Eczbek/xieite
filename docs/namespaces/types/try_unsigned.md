# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:TryUnsigned
Defined in header [<xieite/types/try_unsigned.hpp>](../../../include/xieite/types/try_unsigned.hpp)

&nbsp;

## Description
Attempts to get the unsigned complement of a signed type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
using TryUnsigned = std::conditional_t<std::signed_integral<Type>, std::make_unsigned<Type>, std::type_identity<Type>>::type;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/name.hpp"
#include "xieite/types/try_signed.hpp"

int main() {
    std::println("{}", xieite::types::name<xieite::types::TryUnigned<int>>);
    std::println("{}", xieite::types::name<xieite::types::TryUnigned<double>>);
}
```
Possible output:
```
unsigned int
double
```
