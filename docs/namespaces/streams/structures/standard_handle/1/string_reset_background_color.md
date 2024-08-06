# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:stringResetBackgroundColor\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Returns a string which resets the background color to default when printed.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] static constexpr std::string stringResetBackgroundColor() noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include <string>
#include "xieite/streams/color.hpp"
#include "xieite/streams/standard_handle.hpp"

int main() {
    std::string color = xieite::streams::StandardHandle::stringSetBackgroundColor(xieite::streams::Color<3>(0, 0, 255));
    std::string reset = xieite::streams::StandardHandle::stringResetBackgroundColor();

    std::string message = color + "Hello, " + reset + "world!";

    std::println("{}", message);
}
```
Possible output:

![image](./reset_background_color.png)
