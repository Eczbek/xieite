# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:stringSetTextUnderlined\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Returns a string which enables or disables text <u>underlining</u> when printed.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] static constexpr std::string stringSetTextUnderlined(bool value) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include <string>
#include "xieite/streams/standard_handle.hpp"

int main() {
    std::string underlined = xieite::streams::StandardHandle::stringSetTextUnderlined(true);

    std::string message = underlined + "Hello, world!";

    std::println("{}", message);
}
```
Possible output:

![image](./set_text_underlined.png)
