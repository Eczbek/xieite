# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:TrySigned
Defined in header [<xieite/types/try_signed.hpp>](../../../include/xieite/types/try_signed.hpp)

&nbsp;

## Description
Attempts to get the signed complement of an unsigned type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
using TrySigned = std::conditional_t<xieite::concepts::UnsignedIntegral<Type>, std::make_signed<Type>, std::type_identity<Type>>::type;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/name.hpp"
#include "xieite/types/try_signed.hpp"

int main() {
    std::println("{}", xieite::types::name<xieite::types::TrySigned<unsigned int>>);
    std::println("{}", xieite::types::name<xieite::types::TrySigned<double>>);
}
```
Possible output:
```
int
double
```
