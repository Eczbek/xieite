# [xieite](../../../../../../xieite.md)\:\:[exceptions](../../../../../../exceptions.md)\:\:[UnrepresentableValue](../../../../unrepresentable_value.md)\:\:UnrepresentableValue
Defined in header [<xieite/exceptions/unrepresentable_value.hpp>](../../../../../../../include/xieite/exceptions/unrepresentable_value.hpp)

&nbsp;

Constructs a `xieite::exceptions::UnrepresentableValue`.

## Synopsis
#### 1)
```cpp
UnrepresentableValue(std::string_view message = "") noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/exceptions/unrepresentable_value.hpp"

int main() {
    xieite::exceptions::UnrepresentableValue exception;

    std::println("{}", exception.what());
}
```
Output:
```

```
