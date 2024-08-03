# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:stringSetTextBold\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Returns a string which enables or disables text **boldness** when printed.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] static constexpr std::string stringSetTextBold(bool value) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include <string>
#include "xieite/streams/standard_handle.hpp"

int main() {
    std::string bold = xieite::streams::StandardHandle::stringSetTextBold(true);

    std::string message = bold + "Hello, world!";

    std::println("{}", message);
}
```
Possible output:

![image](./set_text_bold.png)
