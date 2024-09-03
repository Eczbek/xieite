# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:resetForegroundColor\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Resets the text color to default.

&nbsp;

## Synopsis
#### 1)
```cpp
void resetForegroundColor() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.setForegroundColor(xieite::streams::Color<3>(255, 0, 0));
    std::print("Hello, ");
    terminal.resetForegroundColor();
    std::println("world!");
}
```
Possible output:

![image](./reset_foreground_color.png)
