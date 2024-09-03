# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setColorsSwapped\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Enables or disables the swapping of foreground and background colors.

&nbsp;

## Synopsis
#### 1)
```cpp
void setColorsSwapped(bool value) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.setForegroundColor(xieite::streams::Color<3>(255, 0, 0));
    terminal.setBackgroundColor(xieite::streams::Color<3>(0, 0, 255));

    std::print("Hello, ");

    terminal.setColorsSwapped(true);

    std::println("world!");
}
```
Possible output:

![image](./set_colors_swapped.png)
