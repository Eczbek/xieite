# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:resetBackgroundColor\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Resets the background color to default.

&nbsp;

## Synopsis
#### 1)
```cpp
void resetBackgroundColor() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.setBackgroundColor(xieite::streams::Color<3>(0, 0, 255));
    std::print("Hello, ");
    terminal.resetBackgroundColor();
    std::println("world!");
}
```
Possible output:

![image](./reset_background_color.png)
