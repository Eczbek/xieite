# [xieite](../../../../../../xieite.md)\:\:[containers](../../../../../../containers.md)\:\:[FixedString<characters, Character>](../../../../fixed_string.md)\:\:view\(\)
Defined in header [<xieite/containers/fixed_string.hpp>](../../../../../../../include/xieite/containers/fixed_string.hpp)

&nbsp;

Returns a view to the string's data.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::StringView StringView = std::string_view>
[[nodiscard]] constexpr StringView view() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/containers/fixed_string.hpp"

int main() {
    xieite::containers::FixedString string = "Hello, world!";

    std::println("{}", string.view());
}
```
Output:
```
Hello, world!
```
