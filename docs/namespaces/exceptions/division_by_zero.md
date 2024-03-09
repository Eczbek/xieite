# [xieite](../../xieite.md)\:\:[exceptions](../../exceptions.md)\:\:DivisionByZero
Defined in header [<xieite/exceptions/division_by_zero.hpp>](../../../include/xieite/exceptions/division_by_zero.hpp)

&nbsp;

An exception type that indicates an error due to division by zero. Extends `xieite::exceptions::Unspecified`.

&nbsp;

## Synopsis
#### 1)
```cpp
struct DivisionByZero
: xieite::exceptions::Unspecified {
    DivisionByZero(std::string_view = "");
};
```
##### Member functions
- [DivisionByZero](./structures/division_by_zero/1/operators/constructor.md)

&nbsp;

## Example
```cpp
#include "xieite/exceptions/division_by_zero.hpp"

int main() {
    throw xieite::exceptions::DivisionByZero("Something");
}
```
Possible output:
```
terminate called after throwing an instance of 'xieite::exceptions::DivisionByZero'
  what():  Something
Aborted (core dumped)
```
