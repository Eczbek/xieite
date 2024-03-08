# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[FixedString<characters, Character>](../../../../fixed_string.md)\:\:data
Defined in header [<xieite/containers/fixed_string.hpp>](../../../../../../../include/xieite/containers/fixed_string.hpp)

&nbsp;

Returns the string size, not counting the null-terminator.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::size_t& size() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/containers/fixed_string.hpp"

int main() {
    xieite::containers::FixedString string = "Hello, world!";

    std::println("{}", string.size());
}
```
Output:
```
13
```
