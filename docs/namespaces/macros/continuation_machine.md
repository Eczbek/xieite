# [XIEITE](../../macros.md)\_CONTINUATION\_MACHINE\(\)
Defined in header [<xieite/continuation_machine.hpp>](../../../include/xieite/continuation_machine.hpp)

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
#include <xieite/concatenate.hpp>
#include <xieite/continuation_machine.hpp>

import std;

#define AT_1(_, second_, ...) second_
#define CAT_END(lazy_, total_, ...) )lazy_##total_
#define CAT_NEXT(lazy_, total_, value_, ...) (, CAT, XIEITE_CONCATENATE(total_, value_), lazy_##__VA_ARGS__)
#define CAT_PROBE(...) ,CAT_END
#define CAT_CHECK(...) AT_1(__VA_ARGS__)
#define XIEITE_CONTINUATION_MACHINE_CALLBACK_CAT(lazy_, total_, value_, ...) CAT_CHECK(CAT_PROBE value_, CAT_NEXT)(, lazy_##total_, value_, lazy_##__VA_ARGS__)
#define CAT_ALL(...) XIEITE_CONTINUATION_MACHINE(, CAT, , __VA_ARGS__, ())

int main() {
    std::println("{}", CAT_ALL(1, 2, 3, 4, 5, 6));
}
```
Output:
```
123456
```
