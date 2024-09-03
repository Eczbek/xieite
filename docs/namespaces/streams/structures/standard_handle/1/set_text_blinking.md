# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setTextBlinking\(\)
Defined in fragment [xieite:streams.StandardHandle](../../../../../../src/streams/standard_handle.cpp)

&nbsp;

## Description
Enables or disables text blinking.

&nbsp;

## Synopsis
#### 1)
```cpp
void setTextBlinking(bool value) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.setTextBlinking(true);

    std::println("Hello, world!");
}
```
Possible output:

![image](./set_text_blinking.gif)
