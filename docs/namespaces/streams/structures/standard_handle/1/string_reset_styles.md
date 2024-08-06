# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:stringResetStyles\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Returns a string which resets all text and color effects when printed.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] static constexpr std::string stringResetStyles() noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include <string>
#include "xieite/streams/color.hpp"
#include "xieite/streams/standard_handle.hpp"

int main() {
    std::string bold = xieite::streams::StandardHandle::stringSetTextBold(true);
    std::string italic = xieite::streams::StandardHandle::stringSetTextItalic(true);
    std::string fg = xieite::streams::StandardHandle::stringSetForegroundColor(xieite::streams::Color<3>(255, 0, 0));
    std::string bg = xieite::streams::StandardHandle::stringSetBackgroundColor(xieite::streams::Color<3>(0, 0, 255));
    std::string swap = xieite::streams::StandardHandle::stringSetColorsSwapped(true);
    std::string reset = xieite::streams::StandardHandle::stringResetStyles();

    std::string message = bold + italic + fg + bg + swap + "Hello, " + reset + "world!";

    std::println("{}", message);
}
```
Possible output:

![image](./reset_styles.png)
