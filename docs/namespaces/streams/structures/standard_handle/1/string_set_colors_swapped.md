# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:stringSetColorsSwapped\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Returns a string which, when printed, enables or disables the swapping of foreground and background colors.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] static constexpr std::string stringSetColorsSwapped(bool value) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::string fg = xieite::streams::StandardHandle::stringSetForegroundColor(xieite::streams::Color<3>(255, 0, 0));
    std::string bg = xieite::streams::StandardHandle::stringSetBackgroundColor(xieite::streams::Color<3>(0, 0, 255));
    std::string swap = xieite::streams::StandardHandle::stringSetColorsSwapped(true);

    std::string message = fg + bg + "Hello, " + swap + "world!";

    std::println("{}", message);
}
```
Possible output:

![image](./set_colors_swapped.png)
