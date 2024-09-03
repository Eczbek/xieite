# [XIEITE](../../macros.md)\_CONTINUATION\_MACHINE\(\)
Defined in header ["continuation_machine.hpp"](../../../src/macros/continuation_machine.hpp)

&nbsp;

## Description
A continuation machine.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_CONTINATION_MACHINE(...) /* magic */
```

&nbsp;

## Example
```cpp
#include "concatenate.hpp"
#include "continuation_machine.hpp"

import std;

#define AT_1(first, second, ...) second
#define CAT_END(lazy, total, ...) )lazy##total
#define CAT_NEXT(lazy, total, value, ...) (, CAT, XIEITE_CONCATENATE(total, value), lazy##__VA_ARGS__)
#define CAT_PROBE(...) ,CAT_END
#define CAT_CHECK(...) AT_1(__VA_ARGS__)
#define XIEITE_CONTINUATION_MACHINE_CALLBACK_CAT(lazy, total, value, ...) CAT_CHECK(CAT_PROBE value, CAT_NEXT)(, lazy##total, value, lazy##__VA_ARGS__)
#define CAT_ALL(...) XIEITE_CONTINUATION_MACHINE(, CAT, , __VA_ARGS__, ())

int main() {
    std::println("{}", CAT_ALL(1, 2, 3, 4, 5, 6));
}
```
Output:
```
123456
```
