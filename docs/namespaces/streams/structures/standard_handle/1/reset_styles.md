# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:resetStyles\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Resets all text and color effects. Automatically called upon destruction.

&nbsp;

## Synopsis
#### 1)
```cpp
void resetStyles() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.setTextBold(true);
    terminal.setTextItalic(true);
    terminal.setForegroundColor(xieite::streams::Color<3>(255, 0, 0));
    terminal.setBackgroundColor(xieite::streams::Color<3>(0, 0, 255));
    terminal.setColorsSwapped(true);
    std::print("Hello, ");

    terminal.resetStyles();

    std::println("world!");
}
```
Possible output:

![image](./reset_styles.png)
