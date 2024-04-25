# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:MaybeConstant
Defined in header [<xieite/types/maybe_constant.hpp>](../../../include/xieite/types/maybe_constant.hpp)

&nbsp;

## Description
An alias to an optionally constant qualified type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_, bool constant_>
using MaybeConstant = std::conditional_t<constant_, std::add_const<Type_>, std::remove_const<Type_>>::type;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/maybe_constant.hpp"
#include "xieite/types/name.hpp"

int main() {
    std::println("{}", xieite::types::name<xieite::types::MaybeConstant<int, true>>);
    std::println("{}", xieite::types::name<xieite::types::MaybeConstant<int, false>>);
}
```
Possible output:
```
const int
int
```
