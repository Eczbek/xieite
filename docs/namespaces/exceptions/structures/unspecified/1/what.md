# [xieite](../../../../../xieite.md)\:\:[exceptions](../../../../../exceptions.md)\:\:[Unspecified](../../../unspecified.md)\:\:what
Defined in header [<xieite/exceptions/unspecified.hpp>](../../../../../../include/xieite/exceptions/unspecified.hpp)

&nbsp;

## Description
Returns the error message.

## Synopsis
#### 1)
```cpp
[[nodiscard]] const char* what() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/exceptions/unspecified.hpp"

int main() {
    auto exception = xieite::exceptions::Unspecified("Something");

    std::println("{}", exception.what());
}
```
Output:
```
Something
```
