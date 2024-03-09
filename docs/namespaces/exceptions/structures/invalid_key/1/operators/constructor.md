# [xieite](../../../../../../xieite.md)\:\:[exceptions](../../../../../../exceptions.md)\:\:[InvalidKey](../../../../invalid_key.md)\:\:InvalidKey
Defined in header [<xieite/exceptions/invalid_key.hpp>](../../../../../../../include/xieite/exceptions/invalid_key.hpp)

&nbsp;

Constructs a `xieite::exceptions::InvalidKey`.

## Synopsis
#### 1)
```cpp
InvalidKey(std::string_view message = "") noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/exceptions/invalid_key.hpp"

int main() {
    xieite::exceptions::InvalidKey exception;

    std::println("{}", exception.what());
}
```
Output:
```

```
