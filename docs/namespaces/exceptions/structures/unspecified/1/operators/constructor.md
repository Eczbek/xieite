# [xieite](../../../../../../xieite.md)\:\:[exceptions](../../../../../../exceptions.md)\:\:[Unspecified](../../../../unspecified.md)\:\:Unspecified
Defined in header [<xieite/exceptions/unspecified.hpp>](../../../../../../../include/xieite/exceptions/unspecified.hpp)

&nbsp;

## Description
Constructs a `xieite::exceptions::Unspecified`.

## Synopsis
#### 1)
```cpp
Unspecified(std::string_view message = "") noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/exceptions/unspecified.hpp"

int main() {
    xieite::exceptions::Unspecified exception;

    std::println("{}", exception.what());
}
```
Output:
```

```
