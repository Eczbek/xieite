# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:stringSetBackgroundColor\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Returns a string which sets the background color when printed.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] static constexpr std::string stringSetBackgroundColor(const xieite::graphics::Color& color) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include <string>
#include "xieite/streams/color.hpp"
#include "xieite/streams/standard_handle.hpp"

int main() {
    std::string color = xieite::streams::StandardHandle::stringSetBackgroundColor(xieite::streams::Color(255, 0, 0));

    std::string message = color + "Hello, world!";

    std::println("{}", message);
}
```
Possible output:

![image](./set_background_color.png)
