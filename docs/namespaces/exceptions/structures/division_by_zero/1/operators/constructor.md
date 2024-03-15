# [xieite](../../../../../../xieite.md)\:\:[exceptions](../../../../../../exceptions.md)\:\:[DivisionByZero](../../../../division_by_zero.md)\:\:DivisionByZero
Defined in header [<xieite/exceptions/division_by_zero.hpp>](../../../../../../../include/xieite/exceptions/division_by_zero.hpp)

&nbsp;

## Description
Constructs a `xieite::exceptions::DivisionByZero`.

## Synopsis
#### 1)
```cpp
DivisionByZero(std::string_view message = "") noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/exceptions/division_by_zero.hpp"

int main() {
    xieite::exceptions::DivisionByZero exception;

    std::println("{}", exception.what());
}
```
Output:
```

```
