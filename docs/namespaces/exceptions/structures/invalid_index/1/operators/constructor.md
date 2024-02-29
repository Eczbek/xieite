# [xieite](../../../../../../xieite.md)\:\:[exceptions](../../../../../../exceptions.md)\:\:[InvalidIndex](../../../../invalid_index.md)\:\:InvalidIndex
Defined in header [<xieite/exceptions/invalid_index.hpp>](../../../../../../../include/xieite/exceptions/invalid_index.hpp)

&nbsp;

Constructs a `xieite::exceptions::InvalidIndex`.

## Synopsis
#### 1)
```cpp
constexpr InvalidIndex(std::string_view message = "") noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/exceptions/invalid_index.hpp"

int main() {
    xieite::exceptions::InvalidIndex exception;

    std::println("{}", exception.what());
}
```
Output:
```

```
