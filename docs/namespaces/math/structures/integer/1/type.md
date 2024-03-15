# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits, sign>](../../../integer.md)\:\:Type
Defined in header [<xieite/math/integer.hpp>](../../../../../../include/xieite/math/integer.hpp)

&nbsp;

## Description
An alias to the underlying bit-field type.

&nbsp;

## Synopsis
#### 1)
```cpp
using Type = xieite::types::ConditionallySigned<xieite::types::LeastInteger<bits>, sign>;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/integer.hpp"
#include "xieite/types/name.hpp"

int main() {
    using Data = xieite::math::Integer<13, true>::Type;

    std::println("{}", xieite::types::name<Data>);
}
```
Possible output:
```
short int
```
